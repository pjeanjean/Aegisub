// Copyright (c) 2012, Thomas Goyne <plorkyeran@aegisub.org>
//
// Permission to use, copy, modify, and distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//
// Aegisub Project http://www.aegisub.org/

/// @file spellchecker_hunspell.h
/// @see spellchecker_hunspell.cpp
/// @ingroup spelling
///

#ifdef WITH_HUNSPELL

#include <libaegisub/spellchecker.h>

#include <libaegisub/scoped_ptr.h>
#include <libaegisub/signal.h>

#ifndef AGI_PRE
#include <wx/string.h>
#endif

namespace agi { namespace charset { class IconvWrapper; } }
class Hunspell;

/// @brief Hunspell-based spell checker implementation
class HunspellSpellChecker : public agi::SpellChecker {
	/// Hunspell instance
	agi::scoped_ptr<Hunspell> hunspell;

	/// Conversions between the dictionary charset and utf-8
	agi::scoped_ptr<agi::charset::IconvWrapper> conv;
	agi::scoped_ptr<agi::charset::IconvWrapper> rconv;

	/// Languages which we have dictionaries for
	std::vector<std::string> languages;

	/// Path to user-local dictionary.
	wxString userDicPath;

	/// Dictionary language change connection
	agi::signal::Connection lang_listener;
	/// Dictionary language change handler
	void OnLanguageChanged();

	/// Dictionary path change connection
	agi::signal::Connection dict_path_listener;
	/// Dictionary path change handler
	void OnPathChanged();

public:
	HunspellSpellChecker();
	~HunspellSpellChecker();

	void AddWord(std::string const& word);
	bool CanAddWord(std::string const& word);
	bool CheckWord(std::string const& word);
	std::vector<std::string> GetSuggestions(std::string const& word);
	std::vector<std::string> GetLanguageList();
};

#endif
