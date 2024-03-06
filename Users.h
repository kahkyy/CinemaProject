#ifndef USERS_H
#define USERS_H

#include <QString>
extern QString usernames[100];
extern QString passwords[100];
extern int ages[100];
extern int usersCount;

bool isUsernameExists(const QString& username);
void addUser(const QString& username, const QString& password, int age);

#endif // USERS_H
