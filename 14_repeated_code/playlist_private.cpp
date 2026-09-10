#include "playlist_private.h"
#include <limits>

std::ostream& playlist::showArray(std::ostream& os) const
{
    int i;
    int lim = dblArray::size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << dblArray::operator[](i) << " sec";
            if (i != lim - 1)
                os << std::endl;
        }

    } else
        os << "empty array.";
    return os;
}

void playlist::arrayIn(std::istream& is, std::ostream& os)
{
    int lim = dblArray::size();
    for (int i = 0; i < lim; i++)
    {
        os << "#" << (i + 1) << " >> ";
        while (!(is >> dblArray::operator[](i)))
        {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            os << "#" << (i + 1) << " >> ";
        };
    }
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void playlist::input(std::istream& is, std::ostream& os)
{
    os << "Owner:";
    is >> *this;
}

std::ostream& operator<<(std::ostream& os, const playlist& p)
{
    os << "Playlist by " << (const std::string&)p << ":\n";
    p.showArray(os);
    return os;
}


std::istream& operator>>(std::istream& is, playlist& p)
{
    std::getline(is, (std::string&)p);
    if (is.fail())
        return is;
    p.arrayIn(is);
    return is;
}