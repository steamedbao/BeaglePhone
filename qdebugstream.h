#ifndef QDEBUGSTREAM_H
#define QDEBUGSTREAM_H

#include <iostream>
#include <streambuf>
#include <string>

#include "qtextedit.h"

class QDebugStream : public std::basic_streambuf<char>
{
public:
    QDebugStream(std::ostream &stream, QTextEdit* text_edit);
    ~QDebugStream();

protected:

    virtual int_type overflow(int_type v)
    {
        if (v == '\n')
        {
             log_window->append(m_string.c_str());
            m_string.erase(m_string.begin(), m_string.end());
        }
        else
           m_string += v;

         return v;
    }
    virtual std::streamsize xsputn(const char *p, std::streamsize n)
    {
         m_string.append(p, p + n);

        int pos = 0;
        while (static_cast<unsigned>(pos) != std::string::npos)
        {
             pos = m_string.find('\n');
            if (static_cast<unsigned>(pos) != std::string::npos)
            {
                std::string tmp(m_string.begin(), m_string.begin() + pos);
                log_window->append(tmp.c_str());
                m_string.erase(m_string.begin(), m_string.begin() + pos + 1);
            }
        }
        return n;
    }

private:
    std::ostream &m_stream;
    std::streambuf *m_old_buf;
    std::string m_string;


  QTextEdit* log_window;
};
#endif
