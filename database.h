#ifndef DATABASE_H
#define DATABASE_H



class Database
{
public:
    static Database* getInstance(){

        if (instance_ == nullptr){
            instance_ = new Database();
        }

        return instance_;
    }



private:
    Database();
    Database(const Database&) = delete;
    Database& operator= (const Database&) = delete;

    static Database* instance_;
};

#endif // DATABASE_H
