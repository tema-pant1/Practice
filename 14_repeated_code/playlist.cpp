#include "playlist.h"

std::ostream& playlist::showArray(std::ostream& os) const
{
    int i;
    int lim = durations.size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
            os << durations[i] << " sec" <<std::endl;
    } else
        os << "empty array.";
    return os;
}

std::ostream& operator<<(std::ostream& os, const playlist& p)
{
    os << "Playlist by " << p.owner << ":\n";
    p.showArray(os);
    return os;
}