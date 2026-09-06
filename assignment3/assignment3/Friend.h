#ifndef FRIEND_H
#define FRIEND_H

class Friend
{
private:
    int id;
    char* name;
    char** hobbies;//count number of hobbies
    int hobbyCount;

    char** mobno;//count number of mobile numbers
    int mobCount;

    char* email;
    char* bdate;
    char* address;

public:
    Friend();

    void accept();
    void display();

    int getId();
    char* getName();
   // Add hobbies of persons
    bool hasHobby(char* hobby);

    ~Friend();
};

#endif