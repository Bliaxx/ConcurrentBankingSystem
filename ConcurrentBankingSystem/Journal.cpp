#include "Journal.h"

void Journal::ShowLog() const
{
    for (const auto& _t : transactions) {
        _t.Show();
    }
}
