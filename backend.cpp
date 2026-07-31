#include "backend.h"

#include <QProcess>

QString Backend::currentMode()
{
    QProcess process;
    process.start("supergfxctl", {"--get"});
    process.waitForFinished();

    QString output = process.readAllStandardOutput();

    if (output.contains("Integrated", Qt::CaseInsensitive))
        return "Integrated";

    if (output.contains("Hybrid", Qt::CaseInsensitive))
        return "Hybrid";

    if (output.contains("AsusMuxDgpu", Qt::CaseInsensitive))
        return "Ultimate";

    return "Unknown";
}

bool Backend::switchMode(const QString& mode)
{
    QProcess process;

    process.start(
        "pkexec",
        QStringList()
            << "supergfxctl"
            << "-m"
            << mode);

    process.waitForFinished(-1);

    return process.exitCode() == 0;
}
