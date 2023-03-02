/*
 * Copyright (C) 2023 Eugene Hopkinson
 *
 * This file is part of png++ the C++ wrapper for libpng.  PNG++ is free
 * software; the exact copying conditions are as follows:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * 3. The name of the author may not be used to endorse or promote products
 * derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef PNGPP_TEXT_HPP_INCLUDED
#define PNGPP_TEXT_HPP_INCLUDED

#include <png.h>

namespace png
{

    /**
     * \brief PNG text struct extension.  Adds constructors.
     */
    struct text
        : png_text
    {
        explicit text(png_const_charp key,
                      png_const_charp txt,
                      int compression = PNG_TEXT_COMPRESSION_zTXt,
                      size_t text_length = 0,
                      size_t itxt_length = 0,
                      png_charp lang = nullptr,
                      png_charp lang_key = nullptr)
        {
            this->compression = compression;
            this->key = const_cast< png_charp >(key);
            this->png_text::text = const_cast< png_charp>(txt);
            this->text_length = text_length;
            this->itxt_length = itxt_length;
            this->lang = lang;
            this->lang_key = lang_key;
        }

        /**
         * \brief Initializes text with a copy of png_text object.
         */
        text(png_text const& other)
        {
            this->compression = other.compression;
            this->key = other.key;
            this->png_text::text = other.text;
            this->text_length = other.text_length;
            this->itxt_length = other.itxt_length;
            this->lang = other.lang;
            this->lang_key = other.lang_key;
        }
    };

} // namespace png

#endif // PNGPP_TEXT_HPP_INCLUDED
