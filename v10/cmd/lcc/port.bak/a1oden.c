/* a1oden.f -- translated by f2c (version of 5 February 1993  1:37:14).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

extern struct {
    doublereal ds[500];
} cstak_;

#define cstak_1 cstak_

extern struct {
    real theta, egive;
    integer minit, maxit, keejac, ircs;
} a1odem_;

#define a1odem_1 a1odem_

/* Table of constant values */

static integer c__1 = 1;
static integer c__3 = 3;

logical a1oden_(v, nv, t, dt, d, da, error, inmi, errpar)
real *v;
integer *nv;
real *t, *dt;
/* Subroutine */ int (*d) (), (*da) (), (*error) (), (*inmi) ();
real *errpar;
{
    /* System generated locals */
    integer i__1;
    logical ret_val;

    /* Local variables */
    static logical done;
    extern /* Subroutine */ int leave_();
    static integer ivold;
    extern /* Subroutine */ int enter_();
    extern logical a1odeo_();
#define is ((integer *)&cstak_1)
#define ls ((logical *)&cstak_1)
#define rs ((real *)&cstak_1)
#define ws ((real *)&cstak_1)
    static integer ivteta;
    extern integer istkgt_();
    static integer idv, iev, ivt, iev1, iev2;

/* NONLINEAR EQUATION SOLVER FOR IODES. */
/* SCRATCH SPACE ALLOCATED - */
/*     S(A1ODEN) =  4*NV + */
/*                 3*NV REAL + */
/*                 MAX ( S(DA), S(ERROR) ) */
/* REAL WORDS. */
/* THE PORT LIBRARY STACK AND ITS ALIASES. */
    /* Parameter adjustments */
    --errpar;
    --v;

    /* Function Body */
    enter_(&c__1);
    i__1 = *nv << 2;
    ivold = istkgt_(&i__1, &c__3);
    ivteta = ivold + *nv;
    ivt = ivteta + *nv;
    idv = ivt + *nv;
    i__1 = *nv * 3;
    iev = istkgt_(&i__1, &c__3);
    iev1 = iev + *nv;
    iev2 = iev1 + *nv;
    done = a1odeo_(&v[1], nv, t, dt, d, da, error, inmi, &errpar[1], &ws[
	    ivteta - 1], &ws[ivt - 1], &ws[ivold - 1], &rs[iev - 1], &rs[iev1 
	    - 1], &rs[iev2 - 1], &ws[idv - 1], &a1odem_1.theta, &
	    a1odem_1.minit, &a1odem_1.maxit, &a1odem_1.keejac, &a1odem_1.ircs,
	     &a1odem_1.egive);
    leave_();
    ret_val = done;
    return ret_val;
} /* a1oden_ */

#undef ws
#undef rs
#undef ls
#undef is


