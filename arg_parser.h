#include <QCommandLineParser>
#include <QScopedPointer>
#include <QCoreApplication>

#include "errors.h"

QScopedPointer<QCommandLineParser> parse_args(const QCoreApplication& app);
