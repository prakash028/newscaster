/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 1999-2001 The Apache Software Foundation.  All rights
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "Xerces" and "Apache Software Foundation" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact apache\@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache",
 *    nor may "Apache" appear in their name, without prior written
 *    permission of the Apache Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation, and was
 * originally based on software copyright (c) 1999, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

/*
 * $Id: Base64BinaryDatatypeValidator.hpp,v 1.5 2003/01/27 19:24:17 peiyongz Exp $
 * $Log: Base64BinaryDatatypeValidator.hpp,v $
 * Revision 1.5  2003/01/27 19:24:17  peiyongz
 * normalize Base64 data before checking against enumeration.
 *
 * Revision 1.4  2003/01/24 23:18:34  peiyongz
 * normalizeEnumeration() added to remove optional ws in Base64 data.
 *
 * Revision 1.3  2002/12/18 14:17:55  gareth
 * Fix to bug #13438. When you eant a vector that calls delete[] on its members you should use RefArrayVectorOf.
 *
 * Revision 1.2  2002/11/04 14:53:28  tng
 * C++ Namespace Support.
 *
 * Revision 1.1.1.1  2002/02/01 22:22:40  peiyongz
 * sane_include
 *
 * Revision 1.6  2001/09/24 15:33:15  peiyongz
 * DTV Reorganization: virtual methods moved to *.cpp
 *
 * Revision 1.5  2001/09/19 18:49:40  peiyongz
 * DTV reorganization: inherit from AbstractStringVaildator
 *
 */

#if !defined(BASE64BINARY_DATATYPEVALIDATOR_HPP)
#define BASE64BINARY_DATATYPEVALIDATOR_HPP

#include <xercesc/validators/datatype/AbstractStringValidator.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class VALIDATORS_EXPORT Base64BinaryDatatypeValidator : public AbstractStringValidator
{
public:

    // -----------------------------------------------------------------------
    //  Public ctor/dtor
    // -----------------------------------------------------------------------
	/** @name Constructor. */
    //@{

    Base64BinaryDatatypeValidator();

    Base64BinaryDatatypeValidator(DatatypeValidator*            const baseValidator
                                , RefHashTableOf<KVStringPair>* const facets
                                , RefArrayVectorOf<XMLCh>*           const enums
                                , const int                           finalSet);

    virtual ~Base64BinaryDatatypeValidator();

	//@}

    /**
      * Returns an instance of the base datatype validator class
	  * Used by the DatatypeValidatorFactory.
      */
    virtual DatatypeValidator* newInstance(RefHashTableOf<KVStringPair>* const facets
                                         , RefArrayVectorOf<XMLCh>*           const enums
                                         , const int                           finalSet);

protected:

    virtual void assignAdditionalFacet(const XMLCh* const key
                                     , const XMLCh* const value);

    virtual void inheritAdditionalFacet();

    virtual void checkAdditionalFacetConstraints() const;

    virtual void checkAdditionalFacet(const XMLCh* const content) const;

    virtual void checkValueSpace(const XMLCh* const content);

    virtual int  getLength(const XMLCh* const content) const;

    virtual void normalizeEnumeration();

    virtual void normalizeContent(XMLCh* const) const;

private:

    // -----------------------------------------------------------------------
    //  Private data members
    //
    //     Nil
    // -----------------------------------------------------------------------

};

XERCES_CPP_NAMESPACE_END

#endif

/**
  * End of file Base64BinaryDatatypeValidator.hpp
  */
