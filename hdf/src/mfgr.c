/****************************************************************************
 * NCSA HDF                                                                 *
 * Software Development Group                                               *
 * National Center for Supercomputing Applications                          *
 * University of Illinois at Urbana-Champaign                               *
 * 605 E. Springfield, Champaign IL 61820                                   *
 *                                                                          *
 * For conditions of distribution and use, see the accompanying             *
 * hdf/COPYING file.                                                        *
 *                                                                          *
 ****************************************************************************/

#ifdef RCSID
static char RcsId[] = "$Revision$";
#endif

/* $Id$ */

/*
FILE
    mfgr.c

PURPOSE
    Multi-file access to "generic" raster images

REMARKS
    These functions perform manipulate "generic" raster images.  These
    raster images are composed of "pixels" which can have multiple
    components of data-types other than 8-bit unsigned integers.  Each
    image can have multiple palettes associated with it and other 'attributes'
    in the same "name=value" style as the SD*() routines have.

DESIGN
        These routines are modeled loosely after the previous single-file
    DFGR*() routines and the current SD*() routines.  There is a table of
    pointers to sets of raster images stored in the files which have been
    initialized, similar to the current Vgroup/Vdata implementation.  The table
    contains entries for each file which contain pointers to set of information
    about the "global" attributes (for this interface) and to the set of raster
    images in the file.
        Each set of information for each file is stored in memory using
    the tbbt*() routines.
        Each raster image (RI) in the file will be stored in one Vgroup which
    will contain all the RIs created as well as the "global" raster attributes.
        Each RI in the file will be stored as a Vgroup containing the image data
    for each RI as well as the palettes and dataset attributes for that image.
    Also, each RI Vgroup will have a corresponding RIG created with it and
    maintained in parallel, for backward compatibility.

BUGS/LIMITATIONS
   Currently the following design limitations are still in place:
   1 - Cannot have pixels or palette entries which contain mixed variable
        types, ie. all the pixel/palette components must be of the same
        number type.
   2 - Currently all the components must be of valid HDF number types,
        fractional bytes (ie. 6-bit components) or 'plain' multiple byte values
        are not handled, although they can be packed into the next larger
        sized number type in order to hold them.

EXPORTED ROUTINES
int32 GRstart(int32 hdf_file_id)
    - Initializes the GR interface for a particular file. Returns a 'grid' to
        specify the GR group to operate on.
intn GRfileinfo(int32 grid, int32 *n_datasets, int32 *n_attrs)
    - Returns information about the datasets and "global" attributes for the
        GR interface.
intn GRend(int32 grid)
    - Terminates multi-file GR access for a file.

int32 GRcreate(int32 grid,char *name,int32 ncomp,int32 nt,int32 il,int32 *dimsizes)
    - Defines a raster image in a file.  Returns a 'riid' to work with the new
        raster image.
int32 GRselect(int32 grid,int32 index)
    - Selects an existing RI to operate on.
int32 GRnametoindex(int32 grid,char *name)
    - Maps a RI name to an index which is returned.
intn GRgetiminfo(int32 riid,char *name,int32 *ncomp,int32 *nt,int32 *il,int32 *dimsizes,int32 *n_attr)
    - Gets information about an RI which has been selected/created.
intn GRwriteimage(int32 riid,int32 *start,int32 *stride,int32 *edge,VOIDP data)
    - Writes image data to an RI.  Partial dataset writing and subsampling is
        allowed, but only with the dimensions of the dataset (ie. no UNLIMITED
        dimension support)
intn GRreadimage(int32 riid,int32 *start,int32 *stride,int32 *edge,VOIDP data)
    - Read image data from an RI.  Partial reads and subsampling are allowed.
intn GRendaccess(int32 riid)
    - End access to an RI.

int32 GRgetdimid(int32 riid,int32 index)
    - Get a dimension id ('dimid') for an RI to assign atrributes to. [Later]
intn GRsetdimname(int32 dimid,char *name)
    - Set the name of a dimension. [Later]
int32 GRdiminfo(int32 dimid,char *name,int32 *size,int32 *n_attr)
    - Get information about the dimensions attributes and size. [Later]

uint16 GRidtoref(int32 riid)
    - Maps an riid to a reference # for annotating or including in a Vgroup.
int32 GRreftoindex(int32 hdf_file_id,uint16 ref)
    - Maps the reference # of an RI into an index which can be used with
        GRselect.

intn GRreqlutil(int32 riid,intn il)
    - Request that the next LUT read from an RI have a particular interlace.
intn GRreqimageil(int32 riid,intn il)
    - Request that the image read from an RI have a particular interlace.

int32 GRgetlutid(int32 riid,int32 index)
    - Get a palette id ('palid') for an RI.
intn GRgetlutinfo(int32 riid,char *name,int32 *ncomp,int32 *nt,int32 *il,int32 *nentries)
    - Gets information about a palette.
intn GRwritelut(int32 riid,int32 ncomps,int32 nt,int32 il,int32 nentries,VOIDP data)
    - Writes out a palette for an RI.
intn GRreadlut(int32 palid,VOIDP data)
    - Reads a palette from an RI.

int32 GRsetexternalfile(int32 riid,char *filename,int32 offset)
    - Makes the image data of an RI into an external element special element.
intn GRsetaccesstype(int32 riid,uintn accesstype)
    - Sets the access for an RI to be either serial or parallel I/O.
intn GRsetcompress(int32 riid,int32 comp_type,comp_info *cinfo)
    - Makes the image data of an RI into a compressed special element.

intn GRsetattr(int32 dimid|riid|grid,char *name,int32 attr_nt,int32 count,VOIDP data)
    - Write an attribute for an object.
int32 GRattrinfo(int32 dimid|riid|grid,int32 index,char *name,int32 *attr_nt,int32 *count)
    - Get attribute information for an object.
intn GRgetattr(int32 dimid|riid|grid,int32 index,VOIDP data)
    - Read an attribute for an object.
int32 GRfindattr(int32 dimid|riid|grid,char *name)
    - Get the index of an attribute with a given name for an object.

LOCAL ROUTINES

AUTHOR
   Quincey Koziol

MODIFICATION HISTORY
   10/20/94  - Starting writing specs & coding prototype
 */

#define MFGR_MASTER
#include "hdf.h"
#include "hfile.h"
#include "mfgr.h"       /* Multi-file raster information */

/*--------------------------------------------------------------------------
 NAME
    rigcompare
 PURPOSE
    Compare two B-tree keys for equality.
 USAGE
    intn rigcompare(k1, k2, cmparg)
        VOIDP k1, k2;               IN: ptrs to the keys for the tree elements
        intn cmparg;                IN/OUT: unused
 RETURNS
    Returns negative for k2>k1, positive for k2<k1 and 0 for k2=k1
 DESCRIPTION
    Similar to memcmp function, this routine just compares tree keys for
    greater/equal/lesser status.
 GLOBAL VARIABLES
 COMMENTS, BUGS, ASSUMPTIONS

  *** Only called by B-tree routines, should _not_ be called externally ***

 EXAMPLES
 REVISION LOG
--------------------------------------------------------------------------*/
intn rigcompare(VOIDP k1, VOIDP k2, intn cmparg)
{
    /* shut compiler up */
    cmparg = cmparg;

    return ((intn) ((*(int32 *) k1) - (*(int32 *) k2)));    /* valid for integer keys */
}   /* rigcompare */

       
/*--------------------------------------------------------------------------
 NAME
    GRIget_empty_tab
 PURPOSE
    Get the first blank entry in the GR table of id's
 USAGE
    int32 GRIget_empty_tab(hdf_file_id)
        int32 hdf_file_id;          IN: file ID from Hopen
 RETURNS
    Return grid on success or FAIL
 DESCRIPTION
    Gets the next blank entry in the GR table of id's and returns it to
    the calling function.  This is generally only useful for routines that
    start up the interface.  This routine was written so that the size of the
    table could be dynamicly adjusted, instead of just being a static size.
 GLOBAL VARIABLES
 COMMENTS, BUGS, ASSUMPTIONS
 EXAMPLES
 REVISION LOG
--------------------------------------------------------------------------*/
int32 GRIget_empty_tab(int32 hdf_file_id)
{
    uintn u;    /* local counting variable */

    /* search for the first open GR descriptor and return it */
    for(u=0; u<MAX_GR_FILES; u++)
        if(gr_tab[u]==NULL)
            return((int32)u);
    return(FAIL);
} /* end GRIget_empty_tab() */

/*--------------------------------------------------------------------------
 NAME
    GRIget_image_list
 PURPOSE
    Find all the unique raster images in the file
 USAGE
    intn GRIget_image_list(hdf_file_id,gr_info)
        int32 hdf_file_id;          IN: file ID from Hopen
        gr_info_t *gr_info;         IN: # of unique images found
 RETURNS
    Return SUCCEED/FAIL
 DESCRIPTION
    Sifts through all the images in a file and compiles a list of all the
    unique ones.
 GLOBAL VARIABLES
 COMMENTS, BUGS, ASSUMPTIONS
   o Count the maximum number of possible raster images in the file
   o Search through the file for raster images
      - Look for RI8s
      - Look for RIGs
      - Look for an RI Vgroup, then read in RIs & "global" attributes.
   o Eliminate duplicate images
   o Throw all the remaining RI8s, RIGs, and RIs into an internal table with
      appropriate information about each of them
 EXAMPLES
 REVISION LOG
--------------------------------------------------------------------------*/
intn GRIget_image_list(int32 file_id,gr_info_t *gr_ptr)
{
    CONSTR(FUNC, "GRIget_image_list");
    uint16      gr_ref;         /* ref # of the Vgroup containing new-style RIs */
    intn        curr_image;     /* current image gathering information about */
    intn        nimages;        /* total number of potential images */
    int32       nri, nci, nri8, nci8;   /* number of RIs, CIs, RI8s & CI8s */
    struct image_info {
        uint16 grp_tag,grp_ref;         /* tag/ref of the group the image is in */
        uint16 img_tag,img_ref;         /* tag/ref of the image itself */
        uint16 aux_ref;                 /* ref of aux. info about an image */
        int32 offset;                   /* offset of the image data */
    } *img_info;
    uint16      find_tag, find_ref;     /* storage for tag/ref pairs found */
    int32       find_off, find_len;     /* storage for offset/lengths of tag/refs found */
    intn        i, j;           /* local counting variable */

    HEclear();

    /* In a completely psychotic file, there could be RIGs with no corresponding
       RI8s and also RI8s with no corresponding RIGs, so assume the worst
       case and then run through them all to eliminate matched pairs */
    nri = Hnumber(file_id, DFTAG_RI);     /* count the number of RI and CIs */
    if (nri == FAIL)
        HRETURN_ERROR(DFE_INTERNAL, NULL);
    nci = Hnumber(file_id, DFTAG_CI);     /* count the number of RI and CIs */
    if (nci == FAIL)
        HRETURN_ERROR(DFE_INTERNAL, NULL);
    nri8 = Hnumber(file_id, DFTAG_RI8);     /* add the number of RI8 and CI8s */
    if (nri8 == FAIL)
        HRETURN_ERROR(DFE_INTERNAL, NULL);
    nci8 = Hnumber(file_id, DFTAG_CI8);
    if (nci8 == FAIL)
        HRETURN_ERROR(DFE_INTERNAL, NULL);
    nimages = (intn) (nri + nci + nri8 + nci8);

    /* if there are no images just close the file and get out */
    if (nimages == 0)
        return (SUCCEED);

    /* Get space to store the image offsets */
    if ((img_info = (struct image_info *) HDgetspace(nimages * sizeof(struct image_info))) == NULL)
        HRETURN_ERROR(DFE_NOSPACE, FAIL);
    HDmemset(img_info,0,nimages*sizeof(struct image_info));    

    /* search through the GR group for raster images & global attributes */
    curr_image = 0;
    if((gr_ref=(uint16)VSfind(file_id,GR_NAME))!=FAIL)
      {
          int32       gr_key;         /* Vgroup key of the GR Vgroup */

          gr_ptr->gr_ref=gr_ref; /* squirrel this away for later use */

          if((gr_key=Vattach(file_id,(int32)gr_ref,"r"))!=FAIL)
            {
                int32 nobjs=Vntagrefs(gr_key); /* The number of objects in the Vgroup */
                int32 img_key;  /* Vgroup key of an image */
                int32 grp_tag,grp_ref;  /* a tag/ref in the Vgroup */
                int32 img_tag,img_ref;  /* image tag/ref in the Vgroup */
                char textbuf[VGNAMELENMAX + 1];    /* buffer to store the name in */
                
                for(i=0; i<nobjs; i++)
                  {
                      if(Vgettagref(gr_key,i,&grp_tag,&grp_ref)==FAIL)
                          continue;
                      
                      switch(grp_tag)
                        {
                            case DFTAG_VG:  /* should be an image */
                                if((img_key=Vattach(file_id,grp_ref,"r"))!=FAIL)
                                  {
                                    if(Vgetclass(img_key,textbuf)!=FAIL)
                                      {
                                        if(!HDstrcmp(textbuf,RI_NAME))
                                          { /* found an image, whew! */
                                            for(j=0; j<Vntagrefs(img_key); j++)
                                              {
                                                  if(Vgettagref(img_key,j,&img_tag,&img_ref)==FAIL)
                                                      continue;
                                                  if(img_tag==DFTAG_RI)
                                                    {
                                                        img_info[curr_image].grp_tag=grp_tag;
                                                        img_info[curr_image].grp_ref=grp_ref;
                                                        img_info[curr_image].img_tag=img_tag;
                                                        img_info[curr_image].img_ref=img_ref;
                                                        img_info[curr_image].offset = Hoffset(file_id, img_tag, img_ref);     /* store offset */
                                                        curr_image++;
                                                        break;
                                                    } /* end if */
                                              } /* end for */
                                          } /* end if */
                                      } /* end if */
                                    Vdetach(img_key);
                                  } /* end if */
                                break;

                            case DFTAG_VH:  /* must be a "global" attaribute */
                                  {
                                      at_info_t *new_attr;  /* attribute to add to the set of local attributes */
                                      int32 at_key;         /* VData key for the attribute */

                                      if((new_attr=(at_info_t *)HDgetspace(sizeof(at_info_t)))==NULL)
                                          HRETURN_ERROR(DFE_NOSPACE,FAIL);
                                      new_attr->tag=img_tag;
                                      new_attr->ref=img_ref;
                                      new_attr->index=gr_ptr->gattr_count;
                                      new_attr->data_modified=FALSE;
                                      new_attr->meta_modified=FALSE;
                                      new_attr->data=NULL;
                                      if((at_key=VSattach(file_id,(int32)img_ref,"r"))!=FAIL)
                                        {
                                            /* Make certain the attribute only has one field */
                                            if(VFnfields(at_key)!=1)
                                              {
                                                VSdetach(at_key);
                                                HDfreespace(new_attr);
                                                break;
                                              } /* end if */
                                            new_attr->nt=VFfieldtype(at_key,0);
                                            new_attr->len=VFfieldorder(at_key,0);
                                            if(new_attr->len==1)
                                                new_attr->len=VSelts(at_key);

                                            /* Get the name of the image */
                                            if(Vgetname(at_key,textbuf)==FAIL)
                                                sprintf(textbuf,"Attribute #%d",(int)new_attr->index);
                                            if((new_attr->name=(char *)HDgetspace(HDstrlen(textbuf)+1))==NULL)
                                                HRETURN_ERROR(DFE_NOSPACE,FAIL);
                                            HDstrcpy(new_attr->name,textbuf);
                                            tbbtdins(gr_ptr->gattree, (VOIDP) new_attr, NULL);    /* insert the vg instance in B-tree */ 

                                            VSdetach(at_key);
                                        } /* end if */

                                      gr_ptr->gattr_count++;
                                  } /* end case */
                                break;

                            default:
                                break;
                        } /* end switch */
                  } /* end for */
              Vdetach(gr_key);
            } /* end if */
      } /* end if */

    /* Get information about the RIGs in the file */
    find_tag = find_ref = 0;
    while (Hfind(file_id, DFTAG_RIG, DFREF_WILDCARD, &find_tag, &find_ref, &find_off, &find_len, DF_FORWARD) == SUCCEED)
      {
          uint16      elt_tag, elt_ref;   /* tag/ref of items in a RIG */
          int32       group_id;       /* group ID for looking at RIG's */

          /* read RIG into memory */
          if ((group_id = DFdiread(file_id, DFTAG_RIG, find_ref)) == FAIL)
              HRETURN_ERROR(DFE_INTERNAL, FAIL);
          elt_tag = elt_ref = 0;    /* initialize bogus tag/ref */
          while (!DFdiget(group_id, &elt_tag, &elt_ref))
            {   /* get next tag/ref */
                if (elt_tag == DFTAG_CI || elt_tag == DFTAG_RI)
                  {   
                      if (elt_tag > 0 && elt_ref > 0) /* make certain we found an image */
                        {     /* store the information about the image */
                            img_info[curr_image].grp_tag=DFTAG_RIG;
                            img_info[curr_image].grp_ref=find_ref;
                            img_info[curr_image].img_tag=elt_tag;
                            img_info[curr_image].img_ref=elt_ref;
                            img_info[curr_image].offset = Hoffset(file_id, elt_tag, elt_ref);     /* store offset */
                            curr_image++;
                        }     /* end if */
                      break;  /* break out of reading the group */
                  } /* end if */
            } /* end while */
      } /* end while */

    /* go through the RI8s */
    find_tag = find_ref = 0;
    while (Hfind(file_id, DFTAG_RI8, DFREF_WILDCARD, &find_tag, &find_ref, &find_off, &find_len, DF_FORWARD) == SUCCEED)
      {
          img_info[curr_image].grp_tag=DFTAG_NULL;
          img_info[curr_image].grp_ref=DFTAG_NULL;
          img_info[curr_image].img_tag=find_tag;
          img_info[curr_image].img_ref=find_ref;
          img_info[curr_image].offset = find_off;   /* store offset */
          curr_image++;
      }     /* end while */

    /* go through the CI8s */
    find_tag = find_ref = 0;
    while (Hfind(file_id, DFTAG_CI8, DFREF_WILDCARD, &find_tag, &find_ref, &find_off, &find_len, DF_FORWARD) == SUCCEED)
      {
          img_info[curr_image].grp_tag=DFTAG_NULL;
          img_info[curr_image].grp_ref=DFTAG_NULL;
          img_info[curr_image].img_tag=find_tag;
          img_info[curr_image].img_ref=find_ref;
          img_info[curr_image].offset = find_off;   /* store offset */
          curr_image++;
      } /* end while */

    /* Eliminate duplicate images by using the offset of the image data */
    /* Here's a table for how the images will be eliminated: */
    /*
                                    img_info[i].grp_tag
                                    VG              RIG             NULL(RI8)
                               +-----------------+-----------------+--------+
                            VG | j=NULL          | i=NULL          | i=NULL |
                               |                 | j.aux=i.grp_ref |        |
                               +-----------------+-----------------+--------+
    img_info[j].grp_tag     RIG| j=NULL          | j=NULL          | i=NULL |
                               | i.aux=j.grp_ref |                 |        |
                               +-----------------+-----------------+--------+
                      NULL(RI8)| j=NULL          | j=NULL          | j=NULL |
                               +-----------------+-----------------+--------+
    */

    nimages = curr_image;   /* reset the number of images we really have */
    for (i = 0; i < curr_image; i++)
      {     /* go through the images looking for duplicates */
          if(img_info[i].img_tag!=DFTAG_NULL)
              for (j = i+1; j < curr_image; j++)
                {
                    if(img_info[j].img_tag!=DFTAG_NULL)
                        if (img_info[i].offset == img_info[j].offset)
                          {
                              /* eliminate the oldest tag from the match */
                              switch(img_info[i].img_tag) {
                                  case DFTAG_RI:
                                  case DFTAG_CI: /* Newer style raster image, found in RIG & Vgroup */
                                      if(img_info[j].grp_tag==DFTAG_RIG)
                                        {
                                          img_info[j].img_tag=DFTAG_NULL;
                                          if(img_info[i].grp_tag==DFTAG_VG)
                                              img_info[i].aux_ref=img_info[j].grp_ref;
                                        } /* end if */
                                      else
                                          if(img_info[i].grp_tag==DFTAG_VG)
                                              img_info[j].img_tag=DFTAG_NULL;
                                          else
                                            {
                                              img_info[i].img_tag=DFTAG_NULL;
                                              if(img_info[i].grp_tag==DFTAG_RIG)
                                                  img_info[j].aux_ref=img_info[i].grp_ref;
                                            } /* end else */
                                      break;

                                  case DFTAG_RI8:
                                  case DFTAG_CI8: /* Eldest style raster image, no grouping */
                                      if(img_info[j].img_tag!=DFTAG_RI8 && img_info[j].img_tag!=DFTAG_CI8)
                                          img_info[i].img_tag=DFTAG_NULL;
                                      else
                                          img_info[j].img_tag=DFTAG_NULL;
                                      break;

                                  default: /* an image which was eliminated from the list of images */
                                    break;
                                } /* end switch */
                              nimages--;  /* if duplicate found, decrement the number of images */
                          } /* end if */
                } /* end for */
      } /* end for */

    /* Ok, now sort through the file for information about each image found */
    for(i=0; i<curr_image; i++)
      {
          if(img_info[i].img_tag!=DFTAG_NULL)
              switch(img_info[i].grp_tag) {
                  case DFTAG_VG: /* New style raster image, found in a Vgroup */
                      {
                          ri_info_t *new_image; /* ptr to the image to read in */
                          int32 img_key;            /* Vgroup key of an image */
                          int32 img_tag,img_ref;    /* image tag/ref in the Vgroup */
                          char textbuf[VGNAMELENMAX + 1];    /* buffer to store the name in */
                          uint8 ntstring[4];        /* buffer to store NT info */
                          uint8 GRtbuf[64];         /* local buffer for reading RIG info */

                          if((img_key=Vattach(file_id,img_info[i].grp_ref,"r"))!=FAIL)
                            {
                                if((new_image=(ri_info_t *)HDgetspace(sizeof(ri_info_t)))==NULL)
                                  {
                                    HDfreespace((VOIDP) img_info);   /* free offsets */
                                    Hclose(file_id);
                                    HRETURN_ERROR(DFE_NOSPACE,FAIL);
                                  } /* end if */

                                /* Initialize all the fields in the image structure to zeros */
                                HDmemset(new_image,0,sizeof(ri_info_t));

                                /* Get the name of the image */
                                if(Vgetname(img_key,textbuf)==FAIL)
                                    sprintf(textbuf,"Raster Image #%d",(int)curr_image);
                                if((new_image->name=(char *)HDgetspace(HDstrlen(textbuf)+1))==NULL)
                                    HRETURN_ERROR(DFE_NOSPACE,FAIL);
                                HDstrcpy(new_image->name,textbuf);

                                /* Initialize the local attribute tree */
                                new_image->lattr_count = 0;
                                new_image->lattree = tbbtdmake(rigcompare, sizeof(int32));
                                if (new_image->lattree == NULL)
                                    HRETURN_ERROR(DFE_NOSPACE, FAIL);
                                new_image->ri_ref=img_info[i].grp_ref;
                                if(img_info[i].aux_ref!=0)
                                    new_image->rig_ref=img_info[i].aux_ref;
                                else
                                    new_image->rig_ref=DFTAG_NULL;

                                for(j=0; j<Vntagrefs(img_key); j++)
                                  {
                                      if(Vgettagref(img_key,j,&img_tag,&img_ref)==FAIL)
                                          continue;

                                      /* parse this tag/ref pair */
                                      switch(img_tag) {
                                          case DFTAG_RI:
                                          case DFTAG_CI:    /* Regular or compressed image data */
                                              new_image->img_tag=img_tag;
                                              new_image->img_ref=img_ref;
                                              break;

                                          case DFTAG_LUT:   /* Palette */
                                              new_image->lut_tag=img_tag;
                                              new_image->lut_ref=img_ref;
                                              break;

                                          case DFTAG_LD:    /* Palette dimensions */
                                              if (Hgetelement(file_id, img_tag, img_ref, GRtbuf) != FAIL)
                                                {
                                                    uint8      *p;

                                                    p = GRtbuf;
                                                    INT32DECODE(p, new_image->lut_dim.xdim);
                                                    INT32DECODE(p, new_image->lut_dim.ydim);
                                                    UINT16DECODE(p, new_image->lut_dim.nt_tag);
                                                    UINT16DECODE(p, new_image->lut_dim.nt_ref);
                                                    INT16DECODE(p, new_image->lut_dim.ncomps);
                                                    INT16DECODE(p, new_image->lut_dim.il);
                                                    UINT16DECODE(p, new_image->lut_dim.comp_tag);
                                                    UINT16DECODE(p, new_image->lut_dim.comp_ref);
                                                }
                                              else
                                                  HRETURN_ERROR(DFE_READERROR, FAIL);
                                               
                                               /* read NT */
                                              if (Hgetelement(file_id, new_image->lut_dim.nt_tag, new_image->lut_dim.nt_ref, ntstring) == FAIL)
                                                  HRETURN_ERROR(DFE_READERROR, FAIL);

                                              /* check for any valid NT */
                                              if (ntstring[1] == DFNT_NONE)
                                                  break;
                                              
                                              /* set NT info */
                                              new_image->lut_dim.dim_ref = img_ref;
                                              new_image->lut_dim.nt = (int32)ntstring[1];
                                              new_image->lut_dim.file_nt_subclass = (int32)ntstring[3];
                                              if ((new_image->lut_dim.file_nt_subclass != DFNTF_HDFDEFAULT)
                                                    && (new_image->lut_dim.file_nt_subclass!= DFNTF_PC)
                                                    && (new_image->lut_dim.file_nt_subclass!= DFKgetPNSC(new_image->lut_dim.nt, DF_MT)))
                                                  break; /* unknown subclass */
                                              if (new_image->lut_dim.file_nt_subclass!= DFNTF_HDFDEFAULT)
                                                {     /* if native or little endian */
                                                    if (new_image->lut_dim.file_nt_subclass!= DFNTF_PC)   /* native */
                                                        new_image->lut_dim.nt |= (uint32)DFNT_NATIVE;
                                                    else  /* little endian */
                                                        new_image->lut_dim.nt |= (uint32)DFNT_LITEND;
                                                }     /* end if */
                                              break;

                                          case DFTAG_ID:    /* Image description info */
                                              if (Hgetelement(file_id, img_tag, img_ref, GRtbuf) != FAIL)
                                                {
                                                    uint8      *p;

                                                    p = GRtbuf;
                                                    INT32DECODE(p, new_image->img_dim.xdim);
                                                    INT32DECODE(p, new_image->img_dim.ydim);
                                                    UINT16DECODE(p, new_image->img_dim.nt_tag);
                                                    UINT16DECODE(p, new_image->img_dim.nt_ref);
                                                    INT16DECODE(p, new_image->img_dim.ncomps);
                                                    INT16DECODE(p, new_image->img_dim.il);
                                                    UINT16DECODE(p, new_image->img_dim.comp_tag);
                                                    UINT16DECODE(p, new_image->img_dim.comp_ref);
                                                }
                                              else
                                                  HRETURN_ERROR(DFE_READERROR, FAIL);
                                               
                                               /* read NT */
                                              if (Hgetelement(file_id, new_image->img_dim.nt_tag, new_image->img_dim.nt_ref, ntstring) == FAIL)
                                                  HRETURN_ERROR(DFE_READERROR, FAIL);

                                              /* check for any valid NT */
                                              if (ntstring[1] == DFNT_NONE)
                                                  break;
                                              
                                              /* set NT info */
                                              new_image->img_dim.dim_ref=img_ref;
                                              new_image->img_dim.nt = (int32)ntstring[1];
                                              new_image->img_dim.file_nt_subclass = (int32)ntstring[3];
                                              if ((new_image->img_dim.file_nt_subclass != DFNTF_HDFDEFAULT)
                                                    && (new_image->img_dim.file_nt_subclass!= DFNTF_PC)
                                                    && (new_image->img_dim.file_nt_subclass!= DFKgetPNSC(new_image->img_dim.nt, DF_MT)))
                                                  break; /* unknown subclass */
                                              if (new_image->img_dim.file_nt_subclass!= DFNTF_HDFDEFAULT)
                                                {     /* if native or little endian */
                                                    if (new_image->img_dim.file_nt_subclass!= DFNTF_PC)   /* native */
                                                        new_image->img_dim.nt |= (uint32)DFNT_NATIVE;
                                                    else  /* little endian */
                                                        new_image->img_dim.nt |= (uint32)DFNT_LITEND;
                                                }     /* end if */
                                              break;

                                          case DFTAG_VH:    /* Attribute information */
                                              {
                                                  at_info_t *new_attr;  /* attribute to add to the set of local attributes */
                                                  int32 at_key;         /* VData key for the attribute */

                                                  if((new_attr=(at_info_t *)HDgetspace(sizeof(at_info_t)))==NULL)
                                                      HRETURN_ERROR(DFE_NOSPACE,FAIL);
                                                  new_attr->tag=img_tag;
                                                  new_attr->ref=img_ref;
                                                  new_attr->index=new_image->lattr_count;
                                                  new_attr->data_modified=FALSE;
                                                  new_attr->meta_modified=FALSE;
                                                  new_attr->data=NULL;
                                                  if((at_key=VSattach(file_id,(int32)img_ref,"r"))!=FAIL)
                                                    {
                                                        /* Make certain the attribute only has one field */
                                                        if(VFnfields(at_key)!=1)
                                                          {
                                                            VSdetach(at_key);
                                                            HDfreespace(new_attr);
                                                            break;
                                                          } /* end if */
                                                        new_attr->nt=VFfieldtype(at_key,0);
                                                        new_attr->len=VFfieldorder(at_key,0);
                                                        if(new_attr->len==1)
                                                            new_attr->len=VSelts(at_key);

                                                        /* Get the name of the image */
                                                        if(Vgetname(at_key,textbuf)==FAIL)
                                                            sprintf(textbuf,"Attribute #%d",(int)new_attr->index);
                                                        if((new_attr->name=(char *)HDgetspace(HDstrlen(textbuf)+1))==NULL)
                                                            HRETURN_ERROR(DFE_NOSPACE,FAIL);
                                                        HDstrcpy(new_attr->name,textbuf);
                                                        tbbtdins(new_image->lattree, (VOIDP) new_attr, NULL);    /* insert the vg instance in B-tree */ 

                                                        VSdetach(at_key);
                                                    } /* end if */

                                                  new_image->lattr_count++;
                                              } /* end case */
                                              break;

                                          default:          /* Unknown tag */
                                              break;
                                        } /* end switch */
                                  } /* end for */
                              tbbtdins(gr_ptr->grtree, (VOIDP) new_image, NULL);    /* insert the new image into B-tree */ 
                              gr_ptr->gr_count++;
                            } /* end if */
                      } /* end case */
                      break;

                  case DFTAG_RIG:   /* Older style raster image, found in RIG */
                      {
                          int32       GroupID;
                          uint16      elt_tag, elt_ref;
                          ri_info_t *new_image; /* ptr to the image to read in */
                          char textbuf[VGNAMELENMAX + 1];    /* buffer to store the name in */
                          uint8 ntstring[4];        /* buffer to store NT info */
                          uint8 GRtbuf[64];         /* local buffer for reading RIG info */

                          /* read RIG into memory */
                          if ((GroupID = DFdiread(file_id, DFTAG_RIG, img_info[i].grp_ref)) == FAIL)
                              HRETURN_ERROR(DFE_READERROR, FAIL);

                          if((new_image=(ri_info_t *)HDgetspace(sizeof(ri_info_t)))==NULL)
                            {
                              HDfreespace((VOIDP) img_info);   /* free offsets */
                              Hclose(file_id);
                              HRETURN_ERROR(DFE_NOSPACE,FAIL);
                            } /* end if */

                          /* Initialize all the fields in the image structure to zeros */
                          HDmemset(new_image,0,sizeof(ri_info_t));

                          /* Get the name of the image */
                          sprintf(textbuf,"Raster Image #%d",(int)curr_image);
                          if((new_image->name=(char *)HDgetspace(HDstrlen(textbuf)+1))==NULL)
                              HRETURN_ERROR(DFE_NOSPACE,FAIL);
                          HDstrcpy(new_image->name,textbuf);

                          /* Initialize the local attribute tree */
                          new_image->lattree = tbbtdmake(rigcompare, sizeof(int32));
                          if (new_image->lattree == NULL)
                              HRETURN_ERROR(DFE_NOSPACE, FAIL);
                          new_image->ri_ref=DFTAG_NULL;
                          new_image->rig_ref=img_info[i].grp_ref;

                          while (!DFdiget(GroupID, &elt_tag, &elt_ref))
                            {     /* get next tag/ref */
                                switch (elt_tag)
                                  {   /* process tag/ref */
                                      case DFTAG_RI:
                                      case DFTAG_CI:    /* Regular or compressed image data */
                                          new_image->img_tag=elt_tag;
                                          new_image->img_ref=elt_ref;
                                          break;

                                      case DFTAG_LUT:   /* Palette */
                                          new_image->lut_tag=elt_tag;
                                          new_image->lut_ref=elt_ref;
                                          break;

                                      case DFTAG_LD:    /* Palette dimensions */
                                          if (Hgetelement(file_id, elt_tag, elt_ref, GRtbuf) != FAIL)
                                            {
                                                uint8      *p;

                                                p = GRtbuf;
                                                INT32DECODE(p, new_image->lut_dim.xdim);
                                                INT32DECODE(p, new_image->lut_dim.ydim);
                                                UINT16DECODE(p, new_image->lut_dim.nt_tag);
                                                UINT16DECODE(p, new_image->lut_dim.nt_ref);
                                                INT16DECODE(p, new_image->lut_dim.ncomps);
                                                INT16DECODE(p, new_image->lut_dim.il);
                                                UINT16DECODE(p, new_image->lut_dim.comp_tag);
                                                UINT16DECODE(p, new_image->lut_dim.comp_ref);
                                            }
                                          else
                                              HRETURN_ERROR(DFE_READERROR, FAIL);
                                               
                                           /* read NT */
                                          if (Hgetelement(file_id, new_image->lut_dim.nt_tag, new_image->lut_dim.nt_ref, ntstring) == FAIL)
                                              HRETURN_ERROR(DFE_READERROR, FAIL);

                                          /* check for any valid NT */
                                          if (ntstring[1] == DFNT_NONE)
                                              break;
                                              
                                          /* set NT info */
                                          new_image->lut_dim.dim_ref = elt_ref;
                                          new_image->lut_dim.nt = (int32)ntstring[1];
                                          new_image->lut_dim.file_nt_subclass = (int32)ntstring[3];
                                          if ((new_image->lut_dim.file_nt_subclass != DFNTF_HDFDEFAULT)
                                                && (new_image->lut_dim.file_nt_subclass!= DFNTF_PC)
                                                && (new_image->lut_dim.file_nt_subclass!= DFKgetPNSC(new_image->lut_dim.nt, DF_MT)))
                                              break; /* unknown subclass */
                                          if (new_image->lut_dim.file_nt_subclass!= DFNTF_HDFDEFAULT)
                                            {     /* if native or little endian */
                                                if (new_image->lut_dim.file_nt_subclass!= DFNTF_PC)   /* native */
                                                    new_image->lut_dim.nt |= (uint32)DFNT_NATIVE;
                                                else  /* little endian */
                                                    new_image->lut_dim.nt |= (uint32)DFNT_LITEND;
                                            }     /* end if */
                                          break;

                                        case DFTAG_ID:    /* Image description info */
                                            if (Hgetelement(file_id, elt_tag, elt_ref, GRtbuf) != FAIL)
                                              {
                                                  uint8      *p;

                                                  p = GRtbuf;
                                                  INT32DECODE(p, new_image->img_dim.xdim);
                                                  INT32DECODE(p, new_image->img_dim.ydim);
                                                  UINT16DECODE(p, new_image->img_dim.nt_tag);
                                                  UINT16DECODE(p, new_image->img_dim.nt_ref);
                                                  INT16DECODE(p, new_image->img_dim.ncomps);
                                                  INT16DECODE(p, new_image->img_dim.il);
                                                  UINT16DECODE(p, new_image->img_dim.comp_tag);
                                                  UINT16DECODE(p, new_image->img_dim.comp_ref);
                                              }
                                            else
                                                HRETURN_ERROR(DFE_GETELEM, FAIL);
                                               
                                             /* read NT */
                                            if (Hgetelement(file_id, new_image->img_dim.nt_tag, new_image->img_dim.nt_ref, ntstring) == FAIL)
                                                HRETURN_ERROR(DFE_GETELEM, FAIL);

                                            /* check for any valid NT */
                                            if (ntstring[1] == DFNT_NONE)
                                                break;
                                              
                                            /* set NT info */
                                            new_image->img_dim.dim_ref=elt_ref;
                                            new_image->img_dim.nt = (int32)ntstring[1];
                                            new_image->img_dim.file_nt_subclass = (int32)ntstring[3];
                                            if ((new_image->img_dim.file_nt_subclass != DFNTF_HDFDEFAULT)
                                                  && (new_image->img_dim.file_nt_subclass!= DFNTF_PC)
                                                  && (new_image->img_dim.file_nt_subclass!= DFKgetPNSC(new_image->img_dim.nt, DF_MT)))
                                                break; /* unknown subclass */
                                            if (new_image->img_dim.file_nt_subclass!= DFNTF_HDFDEFAULT)
                                              {     /* if native or little endian */
                                                  if (new_image->img_dim.file_nt_subclass!= DFNTF_PC)   /* native */
                                                      new_image->img_dim.nt |= (uint32)DFNT_NATIVE;
                                                  else  /* little endian */
                                                      new_image->img_dim.nt |= (uint32)DFNT_LITEND;
                                              }     /* end if */
                                            break;

                                      default:    /* ignore unknown tags */
                                          break;
                                  } /* end switch */
                            } /* end while */
                        tbbtdins(gr_ptr->grtree, (VOIDP) new_image, NULL);    /* insert the new image into B-tree */ 
                        gr_ptr->gr_count++;
                      } /* end case */
                      break;

                  case DFTAG_NULL:  /* Eldest style raster image, no grouping */
                      {
                          ri_info_t *new_image; /* ptr to the image to read in */
                          char textbuf[VGNAMELENMAX + 1];    /* buffer to store the name in */
                          uint8 GRtbuf[64];         /* local buffer for reading RIG info */

                          if((new_image=(ri_info_t *)HDgetspace(sizeof(ri_info_t)))==NULL)
                            {
                              HDfreespace((VOIDP) img_info);   /* free offsets */
                              Hclose(file_id);
                              HRETURN_ERROR(DFE_NOSPACE,FAIL);
                            } /* end if */

                          /* Initialize all the fields in the image structure to zeros */
                          HDmemset(new_image,0,sizeof(ri_info_t));

                          /* Get the name of the image */
                          sprintf(textbuf,"Raster Image #%d",(int)curr_image);
                          if((new_image->name=(char *)HDgetspace(HDstrlen(textbuf)+1))==NULL)
                              HRETURN_ERROR(DFE_NOSPACE,FAIL);
                          HDstrcpy(new_image->name,textbuf);

                          /* Initialize the local attribute tree */
                          new_image->lattree = tbbtdmake(rigcompare, sizeof(int32));
                          if (new_image->lattree == NULL)
                              HRETURN_ERROR(DFE_NOSPACE, FAIL);
                          new_image->ri_ref=DFTAG_NULL;
                          new_image->rig_ref=DFTAG_NULL;

                          /* Get tag/ref for image */
                          new_image->img_tag=img_info[i].img_tag;
                          new_image->img_ref=img_info[i].img_ref;

                          /* Get dimension information */
                          if (Hgetelement(file_id, DFTAG_ID8, new_image->img_ref, GRtbuf) != FAIL)
                            {
                                uint8      *p;
                                uint16      u;

                                p = GRtbuf;
                                UINT16DECODE(p, u);
                                new_image->img_dim.xdim=(int32)u;
                                UINT16DECODE(p, u);
                                new_image->img_dim.ydim=(int32)u;
                            }   /* end if */
                          else
                              HRETURN_ERROR(DFE_GETELEM, FAIL);

                          /* only 8-bit images, so fill in rest of dim info */
                          new_image->img_dim.dim_ref=DFTAG_NULL;
                          new_image->img_dim.ncomps=1;
                          new_image->img_dim.nt=DFNT_UINT8;
                          new_image->img_dim.file_nt_subclass=DFNTF_HDFDEFAULT;
                          new_image->img_dim.il=MFGR_INTERLACE_PIXEL;
                          new_image->img_dim.nt_tag=DFTAG_NULL;
                          new_image->img_dim.nt_ref=DFTAG_NULL;
                          new_image->img_dim.comp_tag=DFTAG_NULL;
                          new_image->img_dim.comp_ref=DFTAG_NULL;

                          /* Get palette information */
                          if(Hexist(file_id, DFTAG_IP8, new_image->img_ref)==SUCCEED)
                            {
                                new_image->lut_tag=DFTAG_IP8;
                                new_image->lut_ref=new_image->img_ref;

                                /* set palette dimensions too */
                                new_image->lut_dim.dim_ref = DFTAG_NULL;
                                new_image->lut_dim.xdim=256;
                                new_image->lut_dim.ydim=1;
                                new_image->img_dim.ncomps=1;
                                new_image->img_dim.nt=DFNT_UINT8;
                                new_image->img_dim.file_nt_subclass=DFNTF_HDFDEFAULT;
                                new_image->img_dim.il=MFGR_INTERLACE_PIXEL;
                                new_image->img_dim.nt_tag=DFTAG_NULL;
                                new_image->img_dim.nt_ref=DFTAG_NULL;
                                new_image->img_dim.comp_tag=DFTAG_NULL;
                                new_image->img_dim.comp_ref=DFTAG_NULL;
                            } /* end if */
                          else
                                new_image->lut_tag=new_image->lut_ref=DFTAG_NULL;

                        tbbtdins(gr_ptr->grtree, (VOIDP) new_image, NULL);    /* insert the new image into B-tree */ 
                        gr_ptr->gr_count++;
                      } /* end case */
                      break;

                  default: /* an image which was eliminated from the list of images */
                    break;
                } /* end switch */
      } /* end for */

    HDfreespace((VOIDP) img_info);   /* free offsets */
    if (Hclose(file_id) == FAIL)
        HRETURN_ERROR(DFE_CANTCLOSE, FAIL);
    return (SUCCEED);
} /* end GRIget_image_list() */

/*--------------------------------------------------------------------------
 NAME
    GRstart
 PURPOSE
    Initialize the GR*() interface for a given HDF file.
 USAGE
    int32 GRstart(hdf_file_id)
        int32 hdf_file_id;          IN: file ID from Hopen
 RETURNS
    Return grid on success or FAIL
 DESCRIPTION
    Initializes the GR*() interface to operate on the HDF file which was
    specified by hdf_file_id.  This routine must be called before any further
    GR*() routines are called for a file.

 GLOBAL VARIABLES
 COMMENTS, BUGS, ASSUMPTIONS
 EXAMPLES
 REVISION LOG
--------------------------------------------------------------------------*/
int32 GRstart(int32 hdf_file_id)
{
    CONSTR(FUNC, "GRstart");    /* for HERROR */
    intn next_gr;               /* index of the next open space in the gr_tab */
    gr_info_t *gr_ptr;          /* ptr to the new GR information for a file */

    /* clear error stack and check validity of file id */
    HEclear();

    /* check the validity of the file ID */
    if(!VALIDFID(hdf_file_id))
        HRETURN_ERROR(DFE_ARGS, FAIL);

    /* get a GR id */
    if((next_gr=GRIget_empty_tab(hdf_file_id))==FAIL)
        HRETURN_ERROR(DFE_TABLEFULL,FAIL);

    /* allocate space for the GR information for this file */
    if((gr_ptr=(gr_info_t *)HDgetspace(sizeof(gr_info_t)))==NULL)
        HRETURN_ERROR(DFE_NOSPACE,FAIL);

    /* Fire up the Vset interface */
    if(Vstart(hdf_file_id)==FAIL)
        HRETURN_ERROR(DFE_CANTINIT,FAIL);

    /* Initialize the starting information for the interface */
    gr_ptr->hdf_file_id=hdf_file_id;
    gr_ptr->gr_ref=DFTAG_NULL;
    gr_ptr->gr_count=0;
    gr_ptr->grtree = tbbtdmake(rigcompare, sizeof(int32));
    if (gr_ptr->grtree == NULL)
        HRETURN_ERROR(DFE_NOSPACE, FAIL);
    gr_ptr->gr_modified=0;

    gr_ptr->gattr_count=0;
    gr_ptr->gattree = tbbtdmake(rigcompare, sizeof(int32));
    if (gr_ptr->gattree == NULL)
        HRETURN_ERROR(DFE_NOSPACE, FAIL);
    gr_ptr->gattr_modified=0;
    gr_ptr->attr_cache=GR_ATTR_THRESHHOLD;

    /* Go get all the images and attributes in the file */
    if(GRIget_image_list(hdf_file_id,gr_ptr)==FAIL)
        HRETURN_ERROR(DFE_INTERNAL,FAIL);

    /* assign the image info to the GR table */
    gr_tab[next_gr]=gr_ptr;

    /* Return handle to the GR interface to the user */
    return((int32)GRSLOT2ID(hdf_file_id,next_gr));
} /* end GRstart() */

/*--------------------------------------------------------------------------
 NAME
    GRfileinfo
 PURPOSE
    Report high-level information about the GR*() interface for a given file.
 USAGE
    intn GRfileinfo(grid, n_datasets, n_attrs)
        int32 grid;                 IN: GR ID to get information about
        int32 *n_datasets;          OUT: the # of GR datasets in a file
        int32 *n_attrs;             OUT: the # of "global" GR attributes
 RETURNS
    SUCCEED/FAIL
 DESCRIPTION
    Reports general information about the number of datasets and "global"
    attributes for the GR interface.  This routine is generally used to find
    the range of acceptable indices for GRselect calls.
 GLOBAL VARIABLES
 COMMENTS, BUGS, ASSUMPTIONS
 EXAMPLES
 REVISION LOG
--------------------------------------------------------------------------*/
intn GRfileinfo(int32 grid,int32 *n_datasets,int32 *n_attrs)
{
    CONSTR(FUNC, "GRfileinfo");    /* for HERROR */
    int32 gr_idx;   /* index into the gr_tab array */

    /* clear error stack and check validity of file id */
    HEclear();

    /* check the validity of the GR ID */
    if(!VALIDGRID(grid))
        HRETURN_ERROR(DFE_ARGS, FAIL);
    
    /* Get the array index for the grid */
    gr_idx=GRID2SLOT(grid);

/* Get the number of datasets & global attributes from the memory structures */
    if(n_datasets!=NULL)
        *n_datasets=(int32)gr_tab[gr_idx]->gr_count;
    if(n_attrs!=NULL)
        *n_attrs=(int32)gr_tab[gr_idx]->gattr_count;
        
    return(SUCCEED);
} /* end GRfileinfo() */

/*--------------------------------------------------------------------------
 NAME
    GRIupdatemeta
 PURPOSE
    Internal routine to update the meta-data for an image
 USAGE
    intn GRIupdateRIG(hdf_file_id,img_ptr)
        int32 hdf_file_id;          IN: the file ID for the HDF file.
        ri_info_t *img_ptr;         IN: pointer to the image info for the
                                        image to write.
 RETURNS
    SUCCEED/FAIL

 DESCRIPTION
    Write out the meta-information about an image (& palette) to an HDF file.

 GLOBAL VARIABLES
 COMMENTS, BUGS, ASSUMPTIONS
    Shared by both GRIupdateRIG() and GRIupdateRI() calls.
 EXAMPLES
 REVISION LOG
--------------------------------------------------------------------------*/
intn GRIupdatemeta(int32 hdf_file_id,ri_info_t *img_ptr)
{
    CONSTR(FUNC, "GRIupdatemeta");   /* for HERROR */
    uint8 GRtbuf[64];   /* local buffer for reading RIG info */
    uint8 ntstring[4];  /* temporary storage for the number type information */
    uint8 *p;           /* temporary pointer into buffer */

    HEclear();
    if (!HDvalidfid(hdf_file_id) || img_ptr==NULL)
        HRETURN_ERROR(DFE_ARGS, FAIL);

    /* Weird test below to allow for tag/ref values of zero.  (I'll spare */
    /*  everyone my rant about why DFTAG_NULL should have been made zero */
    /*  instead of one... QAK) */
    if(img_ptr->img_dim.nt_ref<=DFTAG_NULL)
        img_ptr->img_dim.nt_ref=Hnewref(hdf_file_id);
    if(img_ptr->img_dim.nt_tag<=DFTAG_NULL)
        img_ptr->img_dim.nt_tag=DFTAG_NT;
    
    /* Write out the raster image's number-type record */
    ntstring[0] = DFNT_VERSION;     /* version */
    ntstring[1] = DFNT_UCHAR;       /* type */
    ntstring[2] = 8;                /* width: RIG data is 8-bit chars */
    ntstring[3] = DFNTC_BYTE;       /* class: data are numeric values */
    if (Hputelement(hdf_file_id, img_ptr->img_dim.nt_tag,
            img_ptr->img_dim.nt_ref, ntstring, (int32) 4) == FAIL)
        HRETURN_ERROR(DFE_PUTELEM, FAIL);
    
    /* Check for a palette with this image */
    if(img_ptr->lut_ref>DFTAG_NULL)
      {
          /* Write out the palette number-type */
          if(img_ptr->lut_dim.nt_ref<=DFTAG_NULL)
              img_ptr->lut_dim.nt_ref=Hnewref(hdf_file_id);
          if(img_ptr->lut_dim.nt_tag<=DFTAG_NULL)
              img_ptr->lut_dim.nt_tag=DFTAG_NT;
          ntstring[0] = DFNT_VERSION;     /* version */
          ntstring[1] = DFNT_UCHAR;       /* type */
          ntstring[2] = 8;                /* width: RIG data is 8-bit chars */
          ntstring[3] = DFNTC_BYTE;       /* class: data are numeric values */
          if (Hputelement(hdf_file_id, img_ptr->lut_dim.nt_tag,
                  img_ptr->lut_dim.nt_ref, ntstring, (int32)4) == FAIL)
              HRETURN_ERROR(DFE_PUTELEM, FAIL);

          /* Write out the palette dimensions */
          p = GRtbuf;
          INT32ENCODE(p, img_ptr->lut_dim.xdim);
          INT32ENCODE(p, img_ptr->lut_dim.ydim);
          UINT16ENCODE(p, img_ptr->lut_dim.nt_tag);
          UINT16ENCODE(p, img_ptr->lut_dim.nt_ref);
          INT16ENCODE(p, img_ptr->lut_dim.ncomps);
          INT16ENCODE(p, img_ptr->lut_dim.il);
          UINT16ENCODE(p, img_ptr->lut_dim.comp_tag);
          UINT16ENCODE(p, img_ptr->lut_dim.comp_ref);
          if(img_ptr->lut_dim.dim_ref<=DFTAG_NULL)
              img_ptr->lut_dim.dim_ref=Hnewref(hdf_file_id);
          if (Hputelement(hdf_file_id, DFTAG_LD, img_ptr->lut_dim.dim_ref, GRtbuf, (int32)(p-GRtbuf)) == FAIL)
              HRETURN_ERROR(DFE_PUTELEM, FAIL);
      } /* end if */

    /* Write out the image dimensions */
    p = GRtbuf;
    INT32ENCODE(p, img_ptr->img_dim.xdim);
    INT32ENCODE(p, img_ptr->img_dim.ydim);
    UINT16ENCODE(p, img_ptr->img_dim.nt_tag);
    UINT16ENCODE(p, img_ptr->img_dim.nt_ref);
    INT16ENCODE(p, img_ptr->img_dim.ncomps);
    INT16ENCODE(p, img_ptr->img_dim.il);
    UINT16ENCODE(p, img_ptr->img_dim.comp_tag);
    UINT16ENCODE(p, img_ptr->img_dim.comp_ref);
    if(img_ptr->img_dim.dim_ref<=DFTAG_NULL)
        img_ptr->img_dim.dim_ref=Hnewref(hdf_file_id);
    if (Hputelement(hdf_file_id, DFTAG_ID, img_ptr->img_dim.dim_ref, GRtbuf, (int32)(p-GRtbuf)) == FAIL)
        HRETURN_ERROR(DFE_PUTELEM, FAIL);

    return(SUCCEED);
} /* end GRIupdatemeta() */

/*--------------------------------------------------------------------------
 NAME
    GRIupdateRIG
 PURPOSE
    Internal routine to update the RIG for an image
 USAGE
    intn GRIupdateRIG(hdf_file_id,img_ptr)
        int32 hdf_file_id;          IN: the file ID for the HDF file.
        ri_info_t *img_ptr;         IN: pointer to the image info for the
                                        image to write.
 RETURNS
    SUCCEED/FAIL

 DESCRIPTION
    Write out the RIG structure to an HDF file.

 GLOBAL VARIABLES
 COMMENTS, BUGS, ASSUMPTIONS
 EXAMPLES
 REVISION LOG
--------------------------------------------------------------------------*/
intn GRIupdateRIG(int32 hdf_file_id,ri_info_t *img_ptr)
{
    CONSTR(FUNC, "GRIupdateRIG");   /* for HERROR */
    int32 GroupID;      /* RIG id for group interface */

    HEclear();
    if (!HDvalidfid(hdf_file_id) || img_ptr==NULL)
        HRETURN_ERROR(DFE_ARGS, FAIL);

    /* Write out the image/palette meta-information */
    if (GRIupdatemeta(hdf_file_id,img_ptr)==FAIL)
        HRETURN_ERROR(DFE_INTERNAL, FAIL);

    /* Write out the RIG itself */
    if ((GroupID = DFdisetup(6)) == FAIL)    /* max 6 tag/refs in set */
        HRETURN_ERROR(DFE_GROUPSETUP, FAIL);

    /* add image dimension tag/ref to RIG */
    if (DFdiput(GroupID, DFTAG_ID, (uint16) img_ptr->img_dim.dim_ref) == FAIL)
        HRETURN_ERROR(DFE_PUTGROUP, FAIL);

    /* add image data tag/ref to RIG */
    if (DFdiput(GroupID, img_ptr->img_tag, img_ptr->img_ref) == FAIL)
        HRETURN_ERROR(DFE_PUTGROUP, FAIL);

    /* Check if we should write palette information */
    if(img_ptr->lut_ref>DFTAG_NULL)
      {
          /* add palette dimension tag/ref to RIG */
          if (DFdiput(GroupID, DFTAG_LD, (uint16) img_ptr->lut_dim.dim_ref) == FAIL)
              HRETURN_ERROR(DFE_PUTGROUP, FAIL);

          /* add palette data tag/ref to RIG */
          if (DFdiput(GroupID, img_ptr->lut_tag, img_ptr->lut_ref) == FAIL)
              HRETURN_ERROR(DFE_PUTGROUP, FAIL);
      } /* end if */

    /* write out RIG */
    if(DFdiwrite(hdf_file_id, GroupID, DFTAG_RIG, img_ptr->rig_ref)==FAIL)
        HRETURN_ERROR(DFE_GROUPWRITE, FAIL);

    return(SUCCEED);
} /* end GRIupdateRIG() */

/*--------------------------------------------------------------------------
 NAME
    GRIupdateRI
 PURPOSE
    Internal routine to update the RI Vgroup for an image
 USAGE
    intn GRIupdateRIG(hdf_file_id,img_ptr)
        int32 hdf_file_id;          IN: the file ID for the HDF file.
        ri_info_t *img_ptr;         IN: pointer to the image info for the
                                        image to write.
 RETURNS
    SUCCEED/FAIL

 DESCRIPTION
    Write out the RI Vgroup to an HDF file.

 GLOBAL VARIABLES
 COMMENTS, BUGS, ASSUMPTIONS
 EXAMPLES
 REVISION LOG
--------------------------------------------------------------------------*/
intn GRIupdateRI(int32 hdf_file_id,ri_info_t *img_ptr)
{
    CONSTR(FUNC, "GRIupdateRI");   /* for HERROR */
    int32 GroupID;      /* RI vgroup id */

    HEclear();
    if (!HDvalidfid(hdf_file_id) || img_ptr==NULL)
        HRETURN_ERROR(DFE_ARGS, FAIL);

    /* Write out the image/palette meta-information */
    if (GRIupdatemeta(hdf_file_id,img_ptr)==FAIL)
        HRETURN_ERROR(DFE_INTERNAL, FAIL);

    /* Write out the RI Vgroup itself */
    if ((GroupID = Vattach(hdf_file_id,(img_ptr->ri_ref>DFTAG_NULL ?
            img_ptr->ri_ref : -1),"w")) == FAIL)
        HRETURN_ERROR(DFE_CANTATTACH, FAIL);

    /* add image dimension tag/ref to RIG */
    if (Vaddtagref(GroupID, DFTAG_ID, (uint16) img_ptr->img_dim.dim_ref) == FAIL)
        HRETURN_ERROR(DFE_CANTADDELEM, FAIL);

    /* add image data tag/ref to RIG */
    if (Vaddtagref(GroupID, img_ptr->img_tag, img_ptr->img_ref) == FAIL)
        HRETURN_ERROR(DFE_CANTADDELEM, FAIL);

    /* Check if we should write palette information */
    if(img_ptr->lut_ref>DFTAG_NULL)
      {
          /* add palette dimension tag/ref to RIG */
          if (Vaddtagref(GroupID, DFTAG_LD, (uint16) img_ptr->lut_dim.dim_ref) == FAIL)
              HRETURN_ERROR(DFE_CANTADDELEM, FAIL);

          /* add palette data tag/ref to RIG */
          if (Vaddtagref(GroupID, img_ptr->lut_tag, img_ptr->lut_ref) == FAIL)
              HRETURN_ERROR(DFE_CANTADDELEM, FAIL);
      } /* end if */

    /* write out RIG */
    if(Vdetach(GroupID)==FAIL)
        HRETURN_ERROR(DFE_CANTDETACH, FAIL);

    return(SUCCEED);
} /* end GRIupdateRI() */

/*--------------------------------------------------------------------------
 NAME
    GRIup_attr_data
 PURPOSE
    Internal routine to update the attribute data
 USAGE
    intn GRIup_attr_data(hdf_file_id,attr_ptr)
        int32 hdf_file_id;          IN: the file ID for the HDF file.
        at_info_t *attr_ptr;        IN: pointer to the attribute info for the
                                        attr. to write.
 RETURNS
    SUCCEED/FAIL

 DESCRIPTION
    Write out the data for an attribute to an HDF file.

 GLOBAL VARIABLES
 COMMENTS, BUGS, ASSUMPTIONS
 EXAMPLES
 REVISION LOG
--------------------------------------------------------------------------*/
intn GRIup_attr_data(int32 hdf_file_id,at_info_t *attr_ptr)
{
    CONSTR(FUNC, "GRIup_attr_data");   /* for HERROR */
    int32 GroupID;      /* attribute Vdata id */

    HEclear();
    if (!HDvalidfid(hdf_file_id) || attr_ptr==NULL)
        HRETURN_ERROR(DFE_ARGS, FAIL);

    /* Write out the attribute data */
    if (attr_ptr->ref==DFTAG_NULL)  /* create a new attribute */
      {
/* QAK */
      } /* end if */
    else    /* update an existing one */
      {
      } /* end else */

#ifdef BROKEN
    /* Write out the RI Vgroup itself */
    if ((GroupID = Vattach(hdf_file_id,(img_ptr->ri_ref>DFTAG_NULL ?
            img_ptr->ri_ref : -1),"w")) == FAIL)
        HRETURN_ERROR(DFE_CANTATTACH, FAIL);

    /* add image dimension tag/ref to RIG */
    if (Vaddtagref(GroupID, DFTAG_ID, (uint16) img_ptr->img_dim.dim_ref) == FAIL)
        HRETURN_ERROR(DFE_CANTADDELEM, FAIL);

    /* add image data tag/ref to RIG */
    if (Vaddtagref(GroupID, img_ptr->img_tag, img_ptr->img_ref) == FAIL)
        HRETURN_ERROR(DFE_CANTADDELEM, FAIL);

    /* Check if we should write palette information */
    if(img_ptr->lut_ref>DFTAG_NULL)
      {
          /* add palette dimension tag/ref to RIG */
          if (Vaddtagref(GroupID, DFTAG_LD, (uint16) img_ptr->lut_dim.dim_ref) == FAIL)
              HRETURN_ERROR(DFE_CANTADDELEM, FAIL);

          /* add palette data tag/ref to RIG */
          if (Vaddtagref(GroupID, img_ptr->lut_tag, img_ptr->lut_ref) == FAIL)
              HRETURN_ERROR(DFE_CANTADDELEM, FAIL);
      } /* end if */

    /* write out RIG */
    if(Vdetach(GroupID)==FAIL)
        HRETURN_ERROR(DFE_CANTDETACH, FAIL);
#endif /* BROKEN */

    return(SUCCEED);
} /* end GRIup_attr_data() */

/*--------------------------------------------------------------------------
 NAME
    GRend
 PURPOSE
    Terminate the GR*() interface for a given HDF file.
 USAGE
    int32 GRend(grid)
        int32 grid;          IN: GR ID from GRstart
 RETURNS
    SUCCEED/FAIL

 DESCRIPTION
    Initializes the GR*() interface to operate on the HDF file which was
    specified by hdf_file_id.  This routine must be called before any further
    GR*() routines are called for a file.

 GLOBAL VARIABLES
 COMMENTS, BUGS, ASSUMPTIONS
 EXAMPLES
 REVISION LOG
--------------------------------------------------------------------------*/
intn GRend(int32 grid)
{
    CONSTR(FUNC, "GRend");      /* for HERROR */
    int32 gr_idx;               /* index into the gr_tab array */
    gr_info_t *gr_ptr;          /* ptr to the GR information for this grid */

    /* clear error stack and check validity of file id */
    HEclear();

    /* check the validity of the GR ID */
    if(!VALIDGRID(grid))
        HRETURN_ERROR(DFE_ARGS, FAIL);
    
    /* Get the array index for the grid */
    gr_idx=GRID2SLOT(grid);
    gr_ptr=gr_tab[gr_idx];

    /* Write out the information for RIs which have been changed */
    if(gr_ptr->gr_modified==TRUE && gr_ptr->gr_count>0)
      {
          VOIDP      *t;
          ri_info_t *img_ptr;   /* ptr to the image */

          if (NULL == (t = (VOIDP *) tbbtfirst((TBBT_NODE *) * (gr_ptr->grtree))))
            {
                HRETURN_ERROR(DFE_NOTINTABLE, FAIL);
            } /* end if */
          else
              img_ptr = (ri_info_t *) * t;   /* get actual pointer to the ri_info_t */

          /* cycle through all of the images in memory */
          while (t!=NULL)
            {
                /* check if the image data has been modified */
                if(img_ptr->data_modified==TRUE)
                  {
                    /* do nothing currently, we are synchronously updating the image data */
                  } /* end if */

                /* check if the image meta-info has been modified */
                if(img_ptr->meta_modified==TRUE)
                  {
                      /* write out the RI/RIG information again */
                      if(GRIupdateRIG(gr_ptr->hdf_file_id,img_ptr)==FAIL)
                          HRETURN_ERROR(DFE_INTERNAL, FAIL);
                      if(GRIupdateRI(gr_ptr->hdf_file_id,img_ptr)==FAIL)
                          HRETURN_ERROR(DFE_INTERNAL, FAIL);
                  } /* end if */

                /* check if the local attributes has been modified */
                if(img_ptr->attr_modified==TRUE && img_ptr->lattr_count>0)
                  {
                      VOIDP      *t;
                      at_info_t *attr_ptr;   /* ptr to the attribute */

                      if (NULL == (t = (VOIDP *) tbbtfirst((TBBT_NODE *) * (img_ptr->lattree))))
                        {
                            HRETURN_ERROR(DFE_NOTINTABLE, FAIL);
                        } /* end if */
                      else
                          attr_ptr = (at_info_t *) * t;   /* get actual pointer to the at_info_t */

                      /* cycle through all of the local attributes in memory */
                      while (t!=NULL)
                        {
                            /* check if the attribute data has been modified */
                            if(attr_ptr->data_modified==TRUE)
                              {
                                  if(GRIup_attr_data(gr_ptr->hdf_file_id,attr_ptr)==FAIL)
                                      HRETURN_ERROR(DFE_INTERNAL, FAIL);
                              } /* end if */

                            /* check if the attribute meta-info has been modified */
                            if(attr_ptr->meta_modified==TRUE)
                              {
                              } /* end if */

                            /* get the next local attribute in the tree/list */
                            if (NULL != (t = (VOIDP *) tbbtnext((TBBT_NODE *) t)))     /* get the next node in the tree */
                                attr_ptr = (at_info_t *) * t;     /* get actual pointer to the at_info_t */
                        } /* end while */
                  } /* end if */

                /* get the next image in the tree/list */
                if (NULL != (t = (VOIDP *) tbbtnext((TBBT_NODE *) t)))     /* get the next node in the tree */
                    img_ptr = (ri_info_t *) * t;     /* get actual pointer to the ri_info_t */
            } /* end while */
      } /* end if */

    /* Write out the information for the global attributes which have been changed */
    if(gr_ptr->gattr_modified==TRUE && gr_ptr->gattr_count>0)
      {
          VOIDP      *t;
          at_info_t *attr_ptr;   /* ptr to the attribute */

          if (NULL == (t = (VOIDP *) tbbtfirst((TBBT_NODE *) * (gr_ptr->gattree))))
            {
                HRETURN_ERROR(DFE_NOTINTABLE, FAIL);
            } /* end if */
          else
              attr_ptr = (at_info_t *) * t;   /* get actual pointer to the at_info_t */

          /* cycle through all of the  global attributes in memory */
          while (t!=NULL)
            {
                /* check if the attribute data has been modified */
                if(attr_ptr->data_modified==TRUE)
                  {
                  } /* end if */

                /* check if the attribute meta-info has been modified */
                if(attr_ptr->meta_modified==TRUE)
                  {
                  } /* end if */

                /* get the next global attribute in the tree/list */
                if (NULL != (t = (VOIDP *) tbbtnext((TBBT_NODE *) t)))     /* get the next node in the tree */
                    attr_ptr = (at_info_t *) * t;     /* get actual pointer to the at_info_t */
            } /* end while */
      } /* end if */

/* Close down the entry for this file in the GR table */
    return(SUCCEED);
} /* end GRend() */
