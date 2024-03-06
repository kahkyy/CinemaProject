#include "Users.h"

QString usernames[100] = {"admin", "test", "user1", "user2"};
QString passwords[100] = {"admin", "1234", "1101", "1102"};
int ages[100] = {20, 21, 22, 23};
int usersCount = 4;

bool isUsernameExists(const QString& username) {
    for (int i = 0; i < usersCount; ++i) {
        if (usernames[i] == username) {
            return true;
        }
    }
    return false;
}
void addUser(const QString& username, const QString& password, int age) {
    usernames[usersCount] = username;
    passwords[usersCount] = password;
    ages[usersCount] = age;

    ++usersCount;
}
