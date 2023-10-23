#ifndef SORT_H
#define SORT_H

class sort {
public:
    void s_bubble(int array[], int size);
    void s_selection(int array[], int size);
    void s_insertion(int array[], int size);
    void s_quick(int array[], int low, int high);
    void s_merge(int array[], int size);
    void s_shell(int array[], int size);
    void s_heap(int array[], int size);
    void s_radixlsd(int array[], int size);
};

#endif // SORT_H