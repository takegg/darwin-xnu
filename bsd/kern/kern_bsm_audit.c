 * Copyright (c) 2003 Apple Computer, Inc. All rights reserved.
 * Copyright (c) 1999-2003 Apple Computer, Inc.  All Rights Reserved.
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
#include <sys/audit.h>
#include <sys/kern_audit.h>
#include <sys/bsm_token.h>
#include <sys/bsm_kevents.h>
#include <sys/bsm_klib.h>
		kmem_alloc(kernel_map, &rec, sizeof(*rec));
		kmem_alloc(kernel_map, &rec->data, 
			   MAX_AUDIT_RECORD_SIZE * sizeof(u_char));
			kmem_free(kernel_map, rec, sizeof(*rec));
		kmem_free(kernel_map, tok->t_data, tok->len);
		kmem_free(kernel_map, tok, sizeof(struct au_token));
			fill_vattr(&vattr, &ar->ar_arg_vnode1);	\
			tok = au_to_attr32(&vattr);		\
			fill_vattr(&vattr, &ar->ar_arg_vnode1);	\
			tok = au_to_attr32(&vattr);		\
			fill_vattr(&vattr, &ar->ar_arg_vnode2);	\
			tok = au_to_attr32(&vattr);		\
				fill_vattr(&vattr, &ar->ar_arg_vnode1);	\
				tok = au_to_attr32(&vattr);		\
	struct vattr vattr;
	int sorf;
	/*
	 * Decide whether to create the BSM audit record by checking the
	 * error value from the system call and using the appropriate
	 * user audit mask. 
	 */
	if (ar->ar_errno) 
		sorf = AU_PRS_FAILURE;
	else
		sorf = AU_PRS_SUCCESS;

	if (au_preselect(ar->ar_event, &ar->ar_subj_amask, sorf) == 0)
		return (BSM_NOAUDIT);

		tok = au_to_arg32(1,"domain", ar->ar_arg_sockinfo.sodomain);
		tok = au_to_arg32(2,"type", ar->ar_arg_sockinfo.sotype);
		tok = au_to_arg32(3,"protocol", ar->ar_arg_sockinfo.soprotocol);
		/* fall through */
/*
 * XXXAUDIT: Close is not audited in the kernel yet. 
*/
		if (ar->ar_arg_text != NULL) {
		/* The open syscall always writes a OPEN_R event; convert the
		 * file flags to the proper type of event.
		 */
		ar->ar_event = flags_to_openevent(ar->ar_arg_fflags);
bsm_rec_verify(caddr_t rec)
	if ( ((char)*rec != AU_HEADER_32_TOKEN) && 
		((char)*rec != AU_HEADER_EX_32_TOKEN) && 
		((char)*rec != AU_HEADER_64_TOKEN) && 
		((char)*rec != AU_HEADER_EX_64_TOKEN) ) {