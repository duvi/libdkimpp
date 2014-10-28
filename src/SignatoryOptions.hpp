/*
 *
 * Copyright (C) 2009-2014 Halon Security <support@halon.se>
 *
 * This file is part of libdkim++.
 *
 * libdkim++ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libdkim++ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with libdkim++.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef _DKIM_SIGNATORYOPTIONS_HPP_
#define _DKIM_SIGNATORYOPTIONS_HPP_

#include "Exception.hpp"
#include "DKIM.hpp"
#include "MailParser.hpp"

using DKIM::Message;

#include "Base64.hpp"

using DKIM::Conversion::Base64;

#include <list>
#include <string>

#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/err.h>

namespace DKIM
{
	class SignatoryOptions
	{
		public:
			SignatoryOptions();
			~SignatoryOptions();

			SignatoryOptions& SetPrivateKey(const std::string& privatekey);
			SignatoryOptions& SetDomain(const std::string& domain);
			SignatoryOptions& SetSelector(const std::string& selector);
			SignatoryOptions& SetAlgorithm(Algorithm algorithm);
			SignatoryOptions& SetHeaders(const std::list<std::string>& headers);
			SignatoryOptions& AddHeaders(const std::list<std::string>& headers);
			SignatoryOptions& SetSignBodyLength(unsigned long bodylength);
			SignatoryOptions& SetCanonModeHeader(CanonMode mode);
			SignatoryOptions& SetCanonModeBody(CanonMode mode);

			EVP_PKEY* GetPrivateKey() const
			{ return m_privateKey; }
			const std::string& GetDomain() const
			{ return m_domain; }
			const std::string& GetSelector() const
			{ return m_selector; }
			Algorithm GetAlgorithm() const
			{ return m_algorithm; }
			const std::list<std::string>& GetHeaders() const
			{ return m_headers; }
			bool GetSignEmptyHeaders() const
			{ return m_signEmptyHeaders; }
			unsigned long GetBodyLength() const
			{ return m_bodyLength; }
			bool GetBodySignLength() const
			{ return m_bodySignLength; }
			CanonMode GetCanonModeHeader() const
			{ return m_canonHead; }
			CanonMode GetCanonModeBody() const
			{ return m_canonBody; }
		private:
			SignatoryOptions(const SignatoryOptions&);

			EVP_PKEY* m_privateKey;
			RSA* m_rsa;

			std::string m_domain;
			std::string m_selector;

			Algorithm m_algorithm;

			std::list<std::string> m_headers;
			bool m_signEmptyHeaders;

			unsigned long m_bodyLength;
			bool m_bodySignLength;

			CanonMode m_canonHead;
			CanonMode m_canonBody;
	};
}

#endif
