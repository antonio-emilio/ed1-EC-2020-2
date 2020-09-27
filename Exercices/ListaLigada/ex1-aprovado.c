#include <stdio.h>
#include <stdlib.h>

typedef int Color;


typedef struct Element{ 
    Color color;
    struct Element* next;

} Dwarf_t;

typedef Dwarf_t* Dwarfs_t;


int insertDwarf(Dwarfs_t* d, Color c){

    Dwarf_t** dwarf = (Dwarf_t**) d;

    while(*dwarf)
        dwarf = (Dwarf_t**) &(*dwarf)->next;

    Dwarf_t* new_dwarf = (Dwarf_t*)  malloc(sizeof(Dwarf_t)); 
    if(!new_dwarf) return -1;

    new_dwarf->color = c;
    new_dwarf->next = NULL;

    *dwarf = new_dwarf;

    return 0;
}

int countMostFrequentColor(Dwarfs_t d, int start, int end, int numb_colors, unsigned int* mostFrequentColor){
    int i;
    int colorsCounter[numb_colors];

    // init colors counter
    for(i = 0; i < numb_colors; i++)
        colorsCounter[i] = 0;

    i = 1;
    while(d && i <= end)
    {
        if(i >= start)
        {
            colorsCounter[d->color - 1]++;
        }
        d = d->next;
        i++;
    }

    int mfc = 0;

    for(i = 0; i < numb_colors; i++)
    {
        if(colorsCounter[i] > mfc)
        {
            *mostFrequentColor = i + 1;
            mfc = colorsCounter[i];
        }
    }


    return mfc;
}

int killDwarfs(Dwarfs_t* d){

    Dwarf_t** dwarf = (Dwarf_t**) d;
    Dwarf_t* dw;

    while(*dwarf)
    {
        dw = *dwarf;
        dwarf = (Dwarf_t**) &(*dwarf)->next;
        free(dw);

    }

    *d = NULL;
}


int main(){

    Dwarfs_t d = NULL;
 
    unsigned int t, i, c, m, most_frequent_color;
    unsigned int start, end;
    int cd, numb_dwarfs, numb_colors;
    
    scanf("%u", &t);

    while(t--)
    {
        scanf("%d %d", &numb_dwarfs, &numb_colors);

        for(i = 0; i < numb_dwarfs; i++)
        {
            scanf("%u", &c);
            insertDwarf(&d, c);
        }

        scanf("%u", &m);

        while(m--)
        {
            scanf("%u %u", &start, &end);
            cd = countMostFrequentColor(d, start, end, numb_colors, &most_frequent_color);
            
            cd > (end - start + 1)/2 ? printf("bonita %u\n", most_frequent_color) : printf("feia\n");

        }
        killDwarfs(&d);

    }

    return 0;
}
