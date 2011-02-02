/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* file: aIOInternal.h						   */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* description: Cross-Platform definition of aIO object and 	   */
/*		routines.					   */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Copyright 1994-2008. Acroname Inc.                              */
/*                                                                 */
/* This software is the property of Acroname Inc.  Any             */
/* distribution, sale, transmission, or re-use of this code is     */
/* strictly forbidden except with permission from Acroname Inc.    */
/*                                                                 */
/* To the full extent allowed by law, Acroname Inc. also excludes  */
/* for itself and its suppliers any liability, wheither based in   */
/* contract or tort (including negligence), for direct,            */
/* incidental, consequential, indirect, special, or punitive       */
/* damages of any kind, or for loss of revenue or profits, loss of */
/* business, loss of information or data, or other financial loss  */
/* arising out of or in connection with this software, even if     */
/* Acroname Inc. has been advised of the possibility of such       */
/* damages.                                                        */
/*                                                                 */
/* Acroname Inc.                                                   */
/* www.acroname.com                                                */
/* 720-564-0373                                                    */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _aIOInternal_H_
#define _aIOInternal_H_

#include "aIO.h"
#include "aCCMap.h"

#define aIOStructHeader				   	   	   \
  ccType		ccMap[128];				   \
  int			check

#define aIOCHECK	0xF11E

#define aVALIDIO(p)						   \
  if ((p == NULL) ||						   \
      (((aIO*)p)->check != aIOCHECK)) {		   		   \
    err = aErrParam;						   \
  }


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This is the basic os-independent aIO structure
 */

typedef struct aIO {
  aIOStructHeader;
} aIO;

aErr aIOInternal_Initialize(aIO* pIO);


#endif /* _aIOInternal_H_ */
