#pragma once

#include <QString>

class Backend
{
public:
    static QString currentMode();
    static bool switchMode(const QString& mode);
};
