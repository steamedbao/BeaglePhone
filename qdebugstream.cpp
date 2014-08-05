#include "qdebugstream.h"
#include <iostream>
#include <streambuf>
#include <string>

QDebugStream::QDebugStream(std::ostream &stream, QTextEdit* text_edit) : m_stream(stream)
{
    log_window = text_edit;
    m_old_buf = stream.rdbuf();
    stream.rdbuf(this);
}
QDebugStream::~QDebugStream()
{
    // output anything that is left
    if (!m_string.empty())
     log_window->append(m_string.c_str());

    m_stream.rdbuf(m_old_buf);
}

