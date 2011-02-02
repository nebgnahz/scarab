/////////////////////////////////////////////////////////////////////
//                                                                 //
// file: acpTag_CAPSULE.h				           //
//                                                                 //
/////////////////////////////////////////////////////////////////////
//                                                                 //
// description: Package tag class.				   //
//                                                                 //
/////////////////////////////////////////////////////////////////////
//                                                                 //
// Copyright 1994-2008. Acroname Inc.                              //
//                                                                 //
// This software is the property of Acroname Inc.  Any             //
// distribution, sale, transmission, or re-use of this code is     //
// strictly forbidden except with permission from Acroname Inc.    //
//                                                                 //
// To the full extent allowed by law, Acroname Inc. also excludes  //
// for itself and its suppliers any liability, wheither based in   //
// contract or tort (including negligence), for direct,            //
// incidental, consequential, indirect, special, or punitive       //
// damages of any kind, or for loss of revenue or profits, loss of //
// business, loss of information or data, or other financial loss  //
// arising out of or in connection with this software, even if     //
// Acroname Inc. has been advised of the possibility of such       //
// damages.                                                        //
//                                                                 //
// Acroname Inc.                                                   //
// www.acroname.com                                                //
// 720-564-0373                                                    //
//                                                                 //
/////////////////////////////////////////////////////////////////////

#ifndef _acpTag_CAPSULE_H_
#define _acpTag_CAPSULE_H_

#include "acpPackageTagID.h"
#include "acpPackageTag.h"

#include "acpVec3.h"
#include "acpFloat.h"



/////////////////////////////////////////////////////////////////////
// CAPSULE = 0x000A

class acpTag_CAPSULE :
  public acpPackageTag
{
  public:
	  			acpTag_CAPSULE();
  				~acpTag_CAPSULE();

    void			setData(
    	                          const aShort nOwnerID,
    				  acpVec3& color,
                                  aReal radius,
                                  aReal length);

    acpPackageTag*		factoryFromStream(
    				  aStreamRef stream);

  protected:
    void			writeData(
    				  aStreamRef stream) const;

  private:
    acpVec3			m_color;
    acpFloat			m_radius;
    acpFloat			m_length;

  friend class			acpCapsule;
};

#endif // _acpTag_CAPSULE_H_
