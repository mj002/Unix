/*
 *	Sydney C Compiler.
 *
 *	Copyright 1984, Bruce Ellis.
 *
 *	Unauthorised possesion, sale or use prohibited.
 */

#define	csync(c)	(global_filename = (c)->c_value.no.no_name, global_lineno = (c)->c_value.no.no_offset)

typedef enum
{
	ct_args,
	ct_binopfsfx,
	ct_binopft,
	ct_binopfv,
	ct_block,
	ct_booltest,
	ct_boolval,
	ct_call,
	ct_callfv,
	ct_dcast,
	ct_clear,
	ct_colon,
	ct_discard,
	ct_fake,
	ct_ftnentry,
	ct_ftnxit,
	ct_hard,
	ct_jmp,
	ct_jmpf,
	ct_jmpt,
	ct_intrin,
	ct_intrinfv,
	ct_label,
	ct_ldiff,
	ct_nop,
	ct_not,
	ct_obj,
	ct_objfv,
	ct_objref,
	ct_question,
	ct_ret,
	ct_switch,
	ct_sync,
	ct_ujmp,
	ct_unopfsfx,
	ct_unopfv,
	ct_vret,
	ct_xnd,
	ct_xndtest,

	ct_char,
	ct_double,
	ct_extern,
	ct_float,
	ct_int,
	ct_long,
	ct_short,
	ct_space,
	ct_ptr,
	ct_string,
}
	cnodes;

struct cnode
{
	/*
	 *	whenever in a list.
	 */
	cnode	*c_next;
	/*
	 *	last	- during optimisation
	 *	type	- codegen and beyond
	 *	symtab	- intrinsics (currently unused)
	 */
	cnode	*c_last;
	/*
	 *	value	- general use
	 *	labs	- label difference (switch table)
	 */
	data	c_value;
	/*
	 *	what	- whenever in a list
	 *	label	- switch labels
	 */
	union
	{
		cnodes	cu_what;
		cnode	*cu_label;
	}
		cu3;
	/*
	 *	choice	- switch tree
	 *	link	- labels
	 *	ids	- register allocation
	 *	xwhat	- codegen operator
	 */
	union
	{
		choice	*cu_choice;
		cnode	*cu_link;
		xnode	*cu_ids;
	}
		cu4;
	/*
	 *	flow_set - opt/flow
	 */
	union
	{
		xnode	*cu_flow;
		cnode	*cu_switch;
	}
		cu5;
	/*
	 *	short1	- flags	(almost everywhere)
	 *	short2	- optimisation
	 */
	short	c_short1;
	short	c_short2;
};



#define	c_label		cu3.cu_label
#define	c_what		cu3.cu_what

#define	c_link		cu4.cu_link
#define	c_choice	cu4.cu_choice
#define	c_ids		cu4.cu_ids

#define	c_left		c_next
#define	c_right		c_last
#define	c_switch	cu5.cu_switch

#define	c_flow		cu5.cu_flow

#define	c_flags		c_short1
#define	c_known		c_short2
#define	c_ord		c_short2

/*
 *	Used in ct_clear nodes for memory layout definitions as passed
 *	to memory().
 */

/*
 *	cnode / xnode flow flags
 *
 *	The first five are the flow sets, the rest
 *	are allocated identifier classes.
 */
#define	C_X_CUT			0x0001
#define	C_X_MOD			0x0002
#define	C_X_REF			0x0004
#define	C_X_HIDE		0x0008
#define	C_X_CMOD		0x0010

#define	C_ID_BEGIN		0x0020
#define	C_ID_END		0x0040
#define	C_ID_BECOMES		0x0080

/*
 *	A switch label ref cnode does not live in the list.
 *	It is on the label ref list and has c_flags & C_SWITCH
 *	Its c_label points to the abel itself and its c_switch
 *	points to the switch.
 */
#define	C_SWITCH		0x0100


struct cfrag
{
	union
	{
		cnode	*c_cn;
		cfrag	*c_cf;
	}
		c_un;
	cnode	*c_tail;
};
#define	c_head	c_un.c_cn
#define	k_next	c_un.c_cf

hocus_pocus(cnodes,cnset);


