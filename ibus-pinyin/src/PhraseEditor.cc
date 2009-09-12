#include "PhraseEditor.h"

namespace PY {

/* init static members */
Database PhraseEditor::m_database;
guint PhraseEditor::m_option = 0;

PhraseEditor::PhraseEditor (void)
    : m_candidates (32),
      m_phrases (8),
      m_pinyin (16),
      m_cursor (0)
{
}

PhraseEditor::~PhraseEditor (void)
{
}

};


