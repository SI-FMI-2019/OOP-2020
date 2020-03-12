#ifndef TV_H
#define TV_H

class TV {
   private:
    char *name = nullptr;

   public:
    TV();
    TV(const char *);
    ~TV();
    TV(const TV &);
    TV &operator=(const TV &);
    const char *getName() const;
};

#endif
