int controller_loadFromText(char* path , LinkedList* pArrayListLibro);
int controller_listLibro(LinkedList* pArrayListLibro);
int controller_sortAutor(LinkedList* pArrayListLibro);
int controller_OrdenamientoPorAutor(void* autor1, void* autor2);
int controller_Descuentos(LinkedList* pArraylistLibro);
void funcion_Descuentos(void* pArrayListLibro);
int controller_saveAsText(char* path , LinkedList* pArrayListLibro);
int controller_FilterMinotauro(LinkedList* pArrayListLibro);
int filter_Minotauro(void* pArrayListLibro);
int reduce_Rowling(void* pArrayListLibro);
int controller_ReduceRowling(LinkedList* pArrayListLibro);

