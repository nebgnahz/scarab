/////////////////////////////////////////////////////////////////////
//                                                                 //
// file: acpTag_GET.h					           //
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

#ifndef _acpTag_GET_H_
#define _acpTag_GET_H_

#include "acpPackageTagID.h"
#include "acpPackageTag.h"

#include "acpStringIO.h"



/////////////////////////////////////////////////////////////////////
// GET = 0x000F

class acpTag_GET :
  public acpPackageTag
{
  public:
	  			acpTag_GET();
    virtual			~acpTag_GET();

    void			setData(
				  const aShort nOwnerID,
				  const char* pApiFile,
				  const aInt32 nUnit,
				  const aByte cParamIndex,
    				  const aByte cParamSize);

    acpPackageTag*		factoryFromStream(
    				  aStreamRef stream);

  protected:
    void			writeData(
    				  aStreamRef stream) const;

  private:
    acpString			m_apifile;
    aInt32			m_nUnit;
    aByte			m_cParamIndex;
    aByte			m_cParamSize;
    char*			m_pApiCup;
    unsigned long		m_ulApiCupSize;

  friend class			acpRobotPackager;
  friend class			acpRobotInternal;
  friend class			acpRobotTEAProperty;
  friend class			acpRobotUserProperty;
};

#endif // _acpTag_GET_H_
