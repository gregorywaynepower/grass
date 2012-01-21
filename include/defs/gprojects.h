#ifndef GRASS_GPROJECTSDEFS_H
#define GRASS_GPROJECTSDEFS_H

/* do_proj.c */
int pj_do_proj(double *, double *, struct pj_info *, struct pj_info *);
int pj_do_transform(int, double *, double *, double *,
		    struct pj_info *, struct pj_info *);

/* get_proj.c */
int pj_get_kv(struct pj_info *, struct Key_Value *, struct Key_Value *);
int pj_get_string(struct pj_info *, char *);
int GPJ_get_equivalent_latlong(struct pj_info *, struct pj_info *);
const char *set_proj_lib(const char *);
int pj_print_proj_params(struct pj_info *, struct pj_info *);

/* convert.c */
char *GPJ_grass_to_wkt(struct Key_Value *, struct Key_Value *, int, int);
#ifdef HAVE_OGR
OGRSpatialReferenceH GPJ_grass_to_osr(struct Key_Value *, struct Key_Value *);
const char *GPJ_set_csv_loc(const char *);
int GPJ_osr_to_grass(struct Cell_head *, struct Key_Value **,
		     struct Key_Value **, OGRSpatialReferenceH, int);
#endif
int GPJ_wkt_to_grass(struct Cell_head *, struct Key_Value **,
		     struct Key_Value **, const char *, int);

/* datum.c */
int GPJ_get_datum_by_name(const char *, struct gpj_datum *);
int GPJ_get_default_datum_params_by_name(const char *, char **);
int GPJ_get_datum_params(char **, char **);
int GPJ__get_datum_params(struct Key_Value *, char **, char **);
void GPJ_free_datum(struct gpj_datum *);
struct gpj_datum_transform_list *GPJ_get_datum_transform_by_name(const char *);
void GPJ_free_datum_transform(struct gpj_datum_transform_list *);

/* ellipse.c */
int GPJ_get_ellipsoid_by_name(const char *, struct gpj_ellps *);
int GPJ_get_ellipsoid_params(double *, double *, double *);
int GPJ__get_ellipsoid_params(struct Key_Value *,
			      double *, double *, double *);
void GPJ_free_ellps(struct gpj_ellps *);


/* PROJ.4's private datastructures copied from projects.h as removed
   from upstream; pending better solution. see:
   http://trac.osgeo.org/proj/ticket/98 */

int pj_factors(LP, void *, double, struct FACTORS *);
/* end of copy */

#endif
