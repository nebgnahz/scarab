/////////////////////////////////////////////////////////////////////
//                                                                 //
// file: acpXmlTag_VIEWS.cpp 		 		                   //
//                                                                 //
/////////////////////////////////////////////////////////////////////
//                                                                 //
// description: Implementation of XML tag class.                   //
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

#include "acpXmlTag_VIEWS.h"

#include "acpTag_VIEWS.h"
#include "acpPkgImport.h"


/////////////////////////////////////////////////////////////////////

bool VIEWS::addTag(
  acpPkgXML* pTag
)
{
  const char* pTagName = pTag->tagName();
  if (!aStringCompare(pTagName, "ROW")
      || !aStringCompare(pTagName, "COLUMN")) 
    return true;

  return false;
}


/////////////////////////////////////////////////////////////////////

void VIEWS::traverse()
{
  aErr err;
  if (aStreamBuffer_Create(m_ioRef, 100, &m_buffer, &err))
    throw acpException(err, "creating buffer for VIEWS tag");

  acpPkgXML::traverse();

  aMemSize size;
  char* pData;
  if (aStreamBuffer_Get(m_ioRef, m_buffer, &size, &pData, &err))
    throw acpException(err, "getting buffer for VIEWS tag");

  if (size) {
    acpTag_VIEWS* pViewTag = new acpTag_VIEWS();
    pViewTag->setData((aShort)size, pData);
    m_pImporter->addTag(this, pViewTag);
  }

  if (aStream_Destroy(m_ioRef, m_buffer, &err))
    throw acpException(err, "destroying buffer for VIEWS tag");
}
