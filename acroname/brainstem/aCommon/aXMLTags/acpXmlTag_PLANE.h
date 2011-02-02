/////////////////////////////////////////////////////////////////////
//                                                                 //
// file: acpXmlTag_PLANE.h 		 		           //
//                                                                 //
/////////////////////////////////////////////////////////////////////
//                                                                 //
// description: Definition of XML tag class.                       //
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

#ifndef _acpXmlTag_PLANE_H_
#define _acpXmlTag_PLANE_H_

#include "acpPkgXML.h"

#include "acpXmlTag_GEOMETRY.h"
#include "acpXmlTag_COLOR.h"
#include "acpXmlTag_VECTOR.h"


class PLANE :
  public GEOMETRY
{
  public:
  			PLANE(
  			  acpPkgImport* pImporter,
  			  acpPkgXML* pParent = NULL) :
  			  GEOMETRY(pImporter, pParent),
  			  m_pColor(NULL),
  			  m_pNormal(NULL),
  			  m_fHeight(0)
  			  {}

    acpPkgXML*		clone(
    			  acpPkgXML* pParent = NULL)
    			  { return new PLANE(m_pImporter, 
    			  		     pParent); }

    bool		equalGeometry(
    			  const acpPkgXML* pTag) const;

    void		addGeometry();

    bool		addTag(
    			  acpPkgXML* pTag);

    const char*  	tagName() const
  			  { return "PLANE"; }

  private:
    COLOR*		m_pColor;
    VECTOR*		m_pNormal;
    float		m_fHeight;
};

#endif // _acpXmlTag_PLANE_H_
