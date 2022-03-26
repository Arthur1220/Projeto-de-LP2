/****
*Título: MyMovieList
*Autor: Arthur Marques Azevedo
        Samyr Ribeiro dos Santos
*Data de Criação: 03/11/2021
*Última modificação: 23/11/21
*
*Descrição: [o que e como o programa faz]
O programa é um sistema para catalogar filmes, séries e documentários, no qual é possivel mostrar o catalogo, adicionar itens, deletar itens,
modificar nota, e ainda pesquisar por um determinado ID ou titulo. O programa é dependente do arquivo "itens.dat" para armazenar todos os dados
dos itens, "abastecendo" as variáveis de listagem (struct).
*
*Entrada: [o tipo de entrada esperada; coloque um exemplo]
As entradas são baseadas em numeros que correspondem a uma respectiva escolha que segue pelo programa, sendo essa responsável por determinar
a operação que o usuário deseja fazer (Excluir item, adicionar, sair, etc). Em determinadas partes será necessário o usuário inserir texto (por exemplo cadastrar um item ou buscar
por título).
*
*Saída: [a saída esperada; um exemplo pode ser recomendável]
O programa possui saidas a partir das escolhas do usuario, sendo elas alguns menus com a operação desejada, como: adicionar item, deletar item,
modificar nota, pesquisar por determinado ID ou titulo.
****/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int id;
    char category[20];
    char title[50];
    int year;
    float rate;
} Catalogo;

/****
*Título: menu() - Menu principal
*Data de Criação: 03/11/21
*Última modificação: 06/11/21
*
*Descrição: A função imprime um display na tela e dá ao usuário algumas opções de entrada.
O display informa o que cada opção realizará, e, caso a entrada seja diferente das opções disponíveis, o
usuário é informado que a opção é inválida, e após pressionar uma tecla, o usuário volta ao menu principal.
*
*Parâmetros: N/A
*
*Valor de retorno: N/A
*
****/
void menu();


/****
*Título: add() - Adicionar item
*Data de Criação: 03/11/21
*Última modificação: 06/11/21
*
*Descrição: A função consiste em adicionar um item novo ao catálogo, onde o usuário fará esse cadastro
de acordo com o que se pede. Para isso, o programa aloca +1 espaço na memória para a variável que armazena todos
os itens do catálogo, e na tela é mostrado o ID atual em que o item será cadastrado, em seguida, o
usuário informará a categoria do item (de acordo com as opções mostradas na tela), título,
ano de lançamento e uma nota entre de 0 a 5. Após ter feito esse processo, o código prosseguirá para a função
de 'save()', ou, salvar arquivo.
*
*Parâmetros: N/A
*
*Valor de retorno: N/A
*
****/
void add(); 


/****
*Título: save() - Salvar arquivo
*Data de Criação: 03/11/21
*Última modificação: 03/11/21
*
*Descrição: Quando o fluxo chega dentro desta função, é gerado um novo arquivo chamado 'itens.dat' (caso não exista),
 e se ele existir, é adicionado todo o conteúdo da variável recém-criada na função add() no final deste arquivo. 
 Formatado da forma: [ID]@[CATEGORIA]@[TITULO]@[ANO DE LANÇAMENTO]@[NOTA] 
*
*Parâmetros: N/A
*
*Valor de retorno: N/A
*
****/
void save(); 


/****
*Título: load_data() - Carregar dados
*Data de Criação: 04/11/21
*Última modificação: 07/11/21
*
*Descrição: A função irá abrir o arquivo 'itens.dat' e para cada item Catalogado ela armazenará os respectivos
dados na variável 'item' (que é um vetor do tipo Catalogo), e para cada item carregado, será realocado dinamicamente 
o espaço na memória referente ao tamanho desse vetor. Além de carregar os dados, a função faz
o uso das variáveis globais 'ID' que conterá qual o último ID armazenado, e 'cont' será utilizada como índice,
que é um contador de quantos itens estão catalogados.
*
*Parâmetros: N/A
*
*Valor de retorno: N/A
*
****/
void load_data();


/****
*Título: show() - Mostrar catalogo
*Data de Criação: 03/11
*Última modificação: 06/11
*
*Descrição: A função imprime um display com opções para mostrar o catálogo de itens, onde o usuário escolherá
entre listar todos os itens por ordem de ID ou se ele deseja listar por uma categoria.
*
*Parâmetros: N/A
*
*Valor de retorno: N/A
*
****/
void show();


/****
*Título: show_by_category(int) - Mostrar por categoria
*Data de Criação: 04/11
*Última modificação: 06/11
*
*Descrição: A função imprime um display com opções para mostrar o catálogo de itens listados pela categoria escolhida
pelo proprio usuario.
*
*Parâmetros: categ - Número inteiro que é referente a categoria escolhida
*
*Valor de retorno: N/A
*
****/
void show_by_category(int);


/****
*Título: delete_menu() - Menu de opções para deletar
*Data de Criação: 04/11
*Última modificação: 06/11
*
*Descrição: A função exibe um menu para o usuário inserir o ID de um item que ele deseja deletar. Se o item
existir, o programa pede para o usuário confirmar a operação, e então será passado esse ID para a função delete,
que será responsável por apagar o item de fato. Caso não exista item com o ID inserido, o usuário será informado
e podera repetir o processo ou sair para o menu.
*
*Parâmetros: N/A
*
*Valor de retorno: N/A
*
****/
void delete_menu();


/****
*Título: delete() - Deletar item
*Data de Criação: 04/11
*Última modificação: 06/11
*
*Descrição: A função recebe o ID de um item que será deletado e decrementa a variável ID (pois terá menos um item)
caso o ID seja 0, so existia um item, então o arquivo com os itens é deletado, e o contador de itens (cont) é
zerado. 
Caso o ID seja diferente de 1, a função irá sobrescrever todo o conteúdo do arquivo até achar o ID que será deletado,
quando chegar nele, ele será 'pulado' e será marcada a flag
'deletado'. Com essa flag, todos os itens seguintes terão ID decrementado, para manter a ordem dos ID's. Ao final do
processo será atualizado o catalogo de itens no programa, através da função load_data().
*
*Parâmetros: del_id - ID do item que será deletado.
*
*Valor de retorno: N/A
*
****/
void delete(int);


/****
*Título: modify_menu() - Menu de modificar
*Data de Criação: 04/11
*Última modificação: 07/11
*
*Descrição: A função exibe um menu para o usuário inserir o ID de um item que ele deseja modificar. Se o item
existir, o programa pede para o usuário confirmar a operação, e então será passado esse ID para a função modify,
que será responsável por modificar o item de fato. Caso não exista item com o ID inserido, o usuário será informado
e podera repetir o processo ou sair para o menu.
*
*Parâmetros: N/A
*
*Valor de retorno: N/A
*
****/
void modify_menu();


/****
*Título: modify() - Modifica item
*Data de Criação: 04/11
*Última modificação: 06/11
*
*Descrição: A função recebe o ID de um item que será modificado, ela altera o seu valor de nota, rate, entre 1-5. Apos 
a função modificar sua nota, será atualizado o catalogo de itens no programa, através da função load_data().
*
*Parâmetros: N/A
*
*Valor de retorno: N/A
*
****/
void modify();
  

/****
*Título: search_menu() - Menu de procurar
*Data de Criação: 04/11
*Última modificação: 06/11
*
*Descrição: A função imprime um display com opções para o usuario procurar um item por titulo/palavra, por seu respectivo ID
ou retornar para o menu.
*
*Parâmetros: N/A
*
*Valor de retorno: N/A
*
****/
void search_menu();


/****
*Título: search_by_title() - Procura pelo titulo
*Data de Criação: 04/11
*Última modificação: 17/11
*
*Descrição: A função imprime um display onde o usuario insere o titulo/palavra pela qual se deseja procurar
um item relacionado, caso o titulo seja encontrado, a função imprime os detalhes do item, caso nao seja 
encontrado a função imprime uma mensagem de erro.
*
*Parâmetros: N/A
*
*Valor de retorno: N/A
*
****/
void search_by_title();


/****
*Título: search_by_id() - Procura pelo id
*Data de Criação: 04/11
*Última modificação: 06/11
*
*Descrição: A função imprime um display onde o usuario insere o ID que deseja procurar, caso o ID
seja encontrado, a função imprime os detalhes do item, caso nao seja encontrado a função imprime uma
mensagem de erro.
*
*Parâmetros: N/A
*
*Valor de retorno: N/A
*
****/
void search_by_id();


/****
*Título: next() - Repete a função ou volta para o menu
*Data de Criação: 06/11
*Última modificação: 06/11
*
*Descrição: A função imprime um display com opções que mostram se o usuario deseja repetir a operação ou retornar para o menu.
*
*Parâmetros: N/A
*
*Valor de retorno: N/A
*
****/
void next();


//VARIAVEIS GLOBAIS
int ID = 1;
int cont = 0;
Catalogo *item;

int main(void){

    load_data();
    //Carrega a struct Catalogo com as informações dos itens do arquivo 'itens.dat', caso não exista o arquivo será definido ID para 0.

    printf("\n|--------------------- BEM VINDO --------------------|\n|");
    printf("\n|  Bem vindo ao 'MyMovieList', o programa de entrete-");
    printf("\n|  nimento acessivel a todos. Nele voce pode: ter acesso ");
    printf("\n|  ao catalogo, fazer buscas por categorias ou itens");
    printf("\n|  especificos, adicionar item ao catalogo, modificar");
    printf("\n|  notas e excluir itens.");
    printf("\n|\n|  Aproveite o nosso servico!");
    printf("\n|\n|----------------------------------------------------|\n\n");

    system("pause");

    menu();

    return 0;
}

//FUNÇÂO CARREGAR DADOS
void load_data(){

    cont = 0;
    
    // Abre ou cria o arquivo "itens.dat" e aloca espaço para pelo menos um item.
    FILE *arquivo = fopen("itens.dat", "r");

    item = (Catalogo *) malloc(1 * sizeof(Catalogo));
    
    // Se não existir o arquivo/der falha ao abrir, o ID vai ser registrado do começo.
    if(arquivo == NULL){
        ID = 0;
    } 
    
    else{
        int i;
        
        // Lê o arquivo até o fim.
        while(!feof(arquivo)){
            
            // Para item registrado no arquivo, é alocado um espaço na memória.
            item = (Catalogo *) realloc(item, (1+cont) * sizeof(Catalogo));

            // Pega o ID do item
            fscanf(arquivo, "%d", &item[cont].id);

            //Limpa o '@' que está no arquivo.
            fgetc(arquivo);

            i = 0;
            // Lê a categoria caractere por caractere, e quando ler o '@', ali será o fim da string. 
            // Adicionando o '\0' no final do conteúdo lido.
            while(1){
                fscanf(arquivo, "%c", &item[cont].category[i]);
                if(item[cont].category[i] == '@'){
                    item[cont].category[i] = '\0';
                    break;
                }//FIM DO IF
                i++;
            }//FIM DO WHILE

            i = 0;
            // Lê a titulo caractere por caractere, e quando ler o '@', ali será o fim da string.
            // Adicionando o '\0' no final do conteúdo lido.
            while(1){
                fscanf(arquivo, "%c", &item[cont].title[i]);
                if(item[cont].title[i] == '@'){
                    item[cont].title[i] = '\0';
                    break;
                }//FIM DO IF
                i++;
            }//FIM DO WHILE
            
            // Lê o Ano de lançamento.
            fscanf(arquivo, "%d", &item[cont].year);

            // Limpa o '@'
            fgetc(arquivo);

            // Lê a nota.
            fscanf(arquivo, "%f", &item[cont].rate);

            cont++; // Incrementa a variável que corresponde à quantidade de itens cadastrados.

        }//FIM DO WHILE
        
        // Após ler todos os itens do arquivo, o ID agora corresponde ao último adicionado.
        ID = item[cont-1].id;
        
    }//FIM DO ELSE
    fclose(arquivo);
}//FIM DA FUNÇÂO DE CARREGAR DADOS

//FUNÇÂO DE MENU
void menu(){

    int option;

    while(1){
        
        // Menu com as operações disponíveis para o usuário.
        system("cls");
        printf("|------------------ BEM VINDO ------------------|");
        printf("\n|");
        printf("\n|     1-> Catalogo;");
        printf("\n|     2-> Buscar;");
        printf("\n|     3-> Adicionar;");
        printf("\n|     4-> Modificar;");
        printf("\n|     5-> Excluir;");
        printf("\n|     6-> Encerrar;");
        printf("\n|");
        printf("\n|-----------------------------------------------|\n");
        printf("\n   -> ");
        scanf("%d",&option);
        
        switch (option){
        case 1:
            show(); // Mostrar catalogo.
            break;
        
        case 2:
            search_menu(); // Menu de Busca.
            break;
        
        case 3:
            add(); // Adicionar item.
            break;

        case 4:
            modify_menu(); // Menu de modificação.
            break;

        case 5:
            delete_menu(); // Menu de deletar.
            break;
        
        case 6:
            // Mensagem de encerrar o programa.
            system("cls");
            printf("\n|------------------ OBRIGADO! ------------------|\n|");
            printf("\n| Obrigado por utilizar nossos servicos!");
            printf("\n|\n|  Feito por: Arthur Marques Azevedo\n|             Samyr Ribeiro dos Santos");
            printf("\n|");
            printf("\n|-----------------------------------------------|\n\n");
            exit(1);
            break;

        default:
            // Aviso de input inválido.
            system("cls");
            printf("\n|---------------- OPCAO INVALIDA ----------------|\n\n");
            system("pause");
            menu();
            break;

        }//FIM DO SWITCH

    }//FIM DO WHILE
    
}//FIM DA FUNÇÃO DE MENU

//FUNÇÂO DE MOSTRAR CATALOGO
void show(){
    
    int i, option = -1, option2 = -1;

    system("cls");
    printf("|------------------ CATALOGO ------------------|\n");

    printf("|\n|\n");
    printf("| 0-> Retornar ao menu;\n");
    printf("| 1-> Por ordem de ID;\n");
    printf("| 2-> Por categoria;\n");
    printf("|\n|\n");
    printf("|----------------------------------------------|");

    // 'option' corresponde às opções para mostrar o catálogo. opções disponíveis: 0,1,2
    while (option < 0 || option > 2){
        printf("\n\n   -> ");
        scanf("%d",&option);

        switch (option)
        {
        case 0:
            menu();
            break;

        // Lista todos os itens por ordem de ID.
        case 1:
            system("cls");
            printf("|----------------- CATALOGO POR ID ----------------|\n");
            for (i = 0; i < cont; i++){
                printf("|\n");

                printf("|   Id:%d\n", item[i].id);
                printf("|   Categoria: %s\n", item[i].category);
                printf("|   Titulo: %s\n", item[i].title);
                printf("|   Ano: %d\n", item[i].year);
                printf("|   Nota: %.2f\n", item[i].rate);
            }//FIM DO FOR
            break;
        
        case 2:
            system("cls");

            // 'option2' corresponde às opções de categorias para listar os itens.
            printf("|------------------ CATALOGO ------------------|");
            printf("\n|");
            printf("\n| Escolha uma categoria para listar:");
            printf("\n|     0-> Retornar;");
            printf("\n|     1-> Filme;");
            printf("\n|     2-> Serie;");
            printf("\n|     3-> Documentario;");
            printf("\n| -> ");
            scanf("%d",&option2);
            
            system("cls");

            switch (option2)
            {
            case 0:
                show(); // Volta ao menu de listar itens.
                break;
            
            case 1:
                //FILME
                printf("|--------------------- FILME ----------------------|\n");
                show_by_category(option2);
                break;
            
            case 2:
                //SERIE
                printf("|--------------------- SERIE ----------------------|\n");
                show_by_category(option2);
                break;

            case 3:
                //DOCUMENTARIO
                printf("|----------------- DOCUMENTARIO -------------------|\n");
                show_by_category(option2);
                break;
            
            default:
                // Aviso de input inválido.
                system("cls");
                printf("|\n|-------------- OPCAO INVALIDA ---------------|\n|\n");
                system("pause");
                menu();
                break;
            }//FIM DO SWITCH

            break;
        
        default:
            // Aviso de input inválido.
            system("cls");
            printf("\n|---------------- OPCAO INVALIDA ----------------|\n\n");
            system("pause");
            show();
            break;
        }//FIM DO SWITCH
    }

    printf("|\n|--------------------------------------------------|\n\n");
    system("pause");

    menu();
    
}//FIM DA FUNÇÃO DE MOSTRAR CATALOGO

//FUNÇÃO DE MOSTRAR POR CATEGORIA
void show_by_category(int categ){
    
    int i;
    char category_def[20];

    // Insere na variável 'category_def' o nome da categoria de acordo com o que o usuário desejou listar.
    switch (categ)
    {
    case 1:
        strcpy(category_def, "Filme");
        break;
    
    case 2:
        strcpy(category_def, "Serie");
        break;
    
    case 3:
        strcpy(category_def, "Documentario");
        break;
    
    default:
        break;
    }//FIM DO SWITCH

    // Imprime na tela todas os itens com a categoria que foi inserida no 'category_def'.
    for (i = 0; i < cont; i++){    
        if(strcmp(item[i].category, category_def) == 0){
            printf("|\n");
            printf("|   Id:%d\n", item[i].id);
            printf("|   Categoria: %s\n", item[i].category);
            printf("|   Titulo: %s\n", item[i].title);
            printf("|   Ano: %d\n", item[i].year);
            printf("|   Nota: %.2f\n", item[i].rate);
        }//FIM DO IF
    }//FIM DO FOR

}//FIM DA FUNÇÃO DE MOSTRAR POR CATEGORIA

// FUNÇÃO DO MENU DE PESQUISA
void search_menu(){
    
    int option = -1;

    // Opções disponíveis: 0,1,2.
    while(option < 0 || option > 2){

        system("cls");
        printf("|----------------- MENU DE BUSCA -----------------|");
        printf("\n|");
        printf("\n| 0-> Retornar ao menu;");
        printf("\n| 1-> Buscar por ID;");
        printf("\n| 2-> Buscar por titulo;");
        printf("\n|\n|-------------------------------------------------|");

        printf("\n\n   -> ");
        scanf("%d",&option);

        switch (option)
        {
        case 0:
            menu(); // Volta ao menu principal
            break;
        case 1:
            // Opção de buscar item por ID.
            search_by_id();
            break;

        case 2:
            // Opção de buscar item por título.
            search_by_title();
            break;

        default:
            // Aviso de input inválido.
            system("cls");
            printf("\n|---------------- OPCAO INVALIDA ----------------|\n\n");
            system("pause");
            break;
        }
    }//FIM DO WHILE

}//FIM DA FUNÇÂO DO MENU DE PESQUISA

void search_by_id(){

    int i, option = -1;

    while (option < 0 || option > ID){

        system("cls");
        printf("|------------------ BUSCA POR ID ------------------|");
        printf("\n|");
        printf("\n|\t    Insira o ID que deseja buscar");
        printf("\n|\t    (Digite 0 caso deseje voltar)");
        printf("\n|\n|--------------------------------------------------|");
        printf("\n\n   -> ");
        scanf("%d",&option);
        
        // SE O USUARIO INSERIR 0, ELE VOLTA AO MENU DE PROCURAR
        if(option == 0){
            search_menu();
        }

        // Procura o ID inserido pelo usuário.
        for  (i = 0; i < cont; i++){
            if (item[i].id == option){
                system("cls");
                printf("|------------------ ID ENCONTRADO ------------------|\n");
                printf("|\n");
                printf("|   Id:%d\n", item[i].id);
                printf("|   Categoria: %s\n", item[i].category);
                printf("|   Titulo: %s\n", item[i].title);
                printf("|   Ano: %d\n", item[i].year);
                printf("|   Nota: %.2f\n", item[i].rate);
                printf("|\n|---------------------------------------------------|\n\n");
                system("pause");

                next(); // Perguntará se o usuário deseja fazer a operação novamente, Se sim, o fluxo continua abaixo, se não, volta ao menu().
                search_menu();
                
                break;
            }//FIM DO IF
        }//FIM DO FOR

        // Aviso que o ID não foi encontrado.
        system("cls");
        printf("|\n|------ ID NAO ENCONTRADO ------|\n\n");
        system("pause");       
        
        next(); // Perguntará se o usuário deseja fazer a operação novamente, Se sim, o fluxo continua abaixo, se não, volta ao menu().
        search_by_id();

    }//FIM DO WHILE

}//FIM DA FUNÇÂO DE PROCURAR POR ID

//FUNÇÃO DE PROCURAR POR TITULO/PALAVRA
void search_by_title(){

    int i, j, find = 0;
    char search[50], copia[50];

    system("cls");
    printf("|---------------- BUSCA POR TITULO ----------------|\n");
    printf("|\n");
    printf("|\t Insira o titulo que deseja buscar\n");
    printf("|\t (Digite 'sair' caso deseje voltar)");
    printf("\n|\n");
    printf("|--------------------------------------------------|");
    printf("\n\n   -> ");

    setbuf(stdin, NULL);
    fgets(search, 50, stdin);
    search[strlen(search)-1] = '\0';

    if(strcmp(search, "sair") == 0){
        search_menu();
    }

    /*Buscar itens pelo título: O usuário deve ser capaz de buscar 
    por um item pelo título (ou parte dele).*/

    system("cls");
    printf("|---------------- TITULO ENCONTRADO ----------------|\n");
    for (i = 0; i < cont; i++){

        // Copia os titulos para uma variável
        strcpy(copia, item[i].title);

        j = 0; // Deixa o conteúdo da busca em lowercase
        while(search[j] != '\0'){
            search[j] = tolower(search[j]);
            j++;
        }//FIM DO WHILE

        j = 0; // Deixa a cópia do título em lowercase
        while(copia[j] != '\0'){
            copia[j] = tolower(copia[j]);
            j++;
        }//FIM DO WHILE

        // Se ele encontrar o conteúdo de busca dentro da string do título, ele imprime as informações do item.
        if (strstr(copia, search) != 0){
            printf("|\n");
            printf("|   Id:%d\n", item[i].id);
            printf("|   Categoria: %s\n", item[i].category);
            printf("|   Titulo: %s\n", item[i].title);
            printf("|   Ano: %d\n", item[i].year);
            printf("|   Nota: %.2f\n", item[i].rate);
            printf("|\n|---------------------------------------------------|\n");

            find = 1;            

        }//FIM DO IF
    }//FIM DO FOR
    
    if(find == 1){
        system("pause");
        next(); // Perguntará se o usuário deseja fazer a operação novamente, Se sim, o fluxo continua abaixo, se não, volta ao menu().
        search_menu();
    }//FIM DO IF
    else{
        // Aviso de que o título não foi encontrado.
        system("cls");
        printf("\n|----------- TITULO NAO ENCONTRADO -----------|\n\n");
        system("pause");
        
        next(); // Perguntará se o usuário deseja fazer a operação novamente, Se sim, o fluxo continua abaixo, se não, volta ao menu().
        search_by_title();
    }//FIM DO ELSE
    
}// FIM DA FUNÇÃO DE PROCURAR POR TITULO/PALAVRA

//FUNÇÂO DE ADICIONAR ITEM
void add(){

    int i;

    system("cls");
    printf("|------------------ ADICIONAR ------------------|");
    printf("\n|");
    //DEFINE ID
    ID++;
    
    // Aloca espaço na memória para um novo item.
    item = (Catalogo *) realloc(item, (1+cont) * sizeof(Catalogo));

    item[cont].id = ID;
    printf("\n| ID: %d", item[cont].id);

    //DEFINE CATEGORIA
    int option = 0;
    while (option > 3 || option < 1){
        printf("\n|");
        printf("\n| Categorias:");
        printf("\n|     1-> Filme");
        printf("\n|     2-> Serie");
        printf("\n|     3-> Documentario");
        printf("\n| -> ");
        scanf("%d",&option);

        switch (option){
        case 1:
            strcpy(item[cont].category, "Filme");
            break;
        
        case 2:
            strcpy(item[cont].category, "Serie");
            break;
        
        case 3:
            strcpy(item[cont].category, "Documentario");
            break;
        
        default:
            printf("|\n|-------------- OPCAO INVALIDA --------------|\n|");
            break;
        }//FIM DO SWITCH
        
    }//FIM DO WHILE
    
    //DEFINE TITULO 
    setbuf(stdin, NULL);
    printf("|\n| Titulo: ");
    fgets(item[cont].title, 50, stdin);

    // Remove o '\n' que o FGETS pega do teclado
    item[cont].title[strlen(item[cont].title)-1] = '\0';

    // Verifica se o título tem '@', caso tenha, ele substitui com um espaço
    int title_size = strlen(item[cont].title);

    for (i = 0; i < title_size; i++){
        if (item[cont].title[i] == '@'){
            item[cont].title[i] = ' ';
        }
    }

    //ANO DE LANÇAMENTO
    printf("|");
    printf("\n| Ano de lancamento: ");
    scanf("%d",&item[cont].year);

    //NOTA DO FILME
    do{
        printf("|");
        printf("\n| Nota [1-5]: ");
        scanf("%f",&item[cont].rate);
        
        // Aviso de input inválido.
        if(item[cont].rate > 5 || item[cont].rate < 1)
            printf("\n|---------------- OPCAO INVALIDA ---------------|\n\n");

    } while (item[cont].rate > 5 || item[cont].rate < 1);
    //FIM DO DOWHILE
    
    //SALVAR ITEM
    save();
    cont++;

    printf("|\n|----------------- SUCESSO! --------------------|\n\n");
    system("pause");

    next(); // Perguntará se o usuário deseja fazer a operação novamente, Se sim, o fluxo continua abaixo, se não, volta ao menu().
    add();

}//FIM DA FUNÇÃO DE ADICIONAR ITEM

// FUNÇÂO DE SALVAR UM ITEM
void save(){

    FILE *arquivo;

    // Abre/cria o arquivo "itens.dat".
    arquivo = fopen("itens.dat", "a");

    // Se o ID não for 1, será sinalizado a quebra de linha para então inserir as informações do item.
    if(item[cont].id != 1){
        fprintf(arquivo, "\n");
    }//FIM DO IF

    // Armazena todo o conteúdo do item no arquivo.
    fprintf(arquivo, "%d@%s@%s@%d@%f", item[cont].id, item[cont].category, item[cont].title, item[cont].year, item[cont].rate);

    fclose(arquivo);
    
}//FIM DA FUNÇÃO DE SALVAR UM ITEM

//FUNÇÃO MENU DE MODIFICAR ITEM
void modify_menu(){

    int option = -1;
    float rate;

    while(option < 0 || option > ID){

        system("cls");
        printf("|------------------ MODIFICAR NOTA------------------|");
        printf("\n|");
        printf("\n|   Insira o ID do item que deseja modificar a nota: ");
        printf("\n|\t    (Digite 0 caso deseje voltar)");
        printf("\n|\n   -> ");
        scanf("%d",&option);

        if (option == 0){
            menu();
        }//FIM DO IF

        if (option > 0 && option <= ID){
            
            printf("\n|---------------------------------------------------|\n|\n");
            printf("|   Id:%d\n", item[option-1].id);
            printf("|   Categoria: %s\n", item[option-1].category);
            printf("|   Titulo: %s\n", item[option-1].title);
            printf("|   Ano: %d\n", item[option-1].year);
            printf("|   Nota: %.2f\n", item[option-1].rate);

            do{
                printf("|");
                printf("\n| Insira a nova nota [0-5]: ");
                scanf("%f",&rate);
                
                if(rate > 5 || rate < 1)
                    printf("\n|\n|----------------- OPCAO INVALIDA ----------------|\n|");

            } while (rate > 5 || rate < 1);

            // Altera a nota do item informado em 'option' para o valor de 'rate'.
            item[option-1].rate = rate;
            
            modify();
            next(); // Perguntará se o usuário deseja fazer a operação novamente, Se sim, o fluxo continua abaixo, se não, volta ao menu().
            modify_menu();
 
        }//FIM DO ELSE

        // Aviso de input inválido.
        system("cls");
        printf("\n|----------- ID NAO ENCONTRADO -----------|\n\n");
        system("pause");
        next(); // Perguntará se o usuário deseja fazer a operação novamente, Se sim, o fluxo continua abaixo, se não, volta ao menu().
        modify_menu();
        
    }//FIM DO WHILE

    
}//FIM DA FUNÇÂO MENU DE MODIFICAR ITEM

//FUNÇÃO DE MOFICAR ITEM
void modify(){

    int i;

    FILE *arquivo;

    // Abre o arquivo.
    arquivo = fopen("itens.dat", "w");
    
    // Sobrescreve todo o arquivo, para armazenar a nota modificada de um item.
    for(i = 0; i < cont; i++){

        if(item[i].id != 1){
            fprintf(arquivo, "\n");
        }

        fprintf(arquivo, "%d@%s@%s@%d@%f", item[i].id, item[i].category, item[i].title, item[i].year, item[i].rate);
        
    }
    fclose(arquivo);

    load_data();
    
    system("cls");
    printf("\n|------------------ ITEM MODIFICADO COM SUCESSO! ------------------|\n\n");
    system("pause");

}//FIM DA FUNÇÃO DE MOFICAR ITEM

//FUNÇÂO MENU DE DELETAR ITEM
void delete_menu(){

    int del_id= -1, option = 0;

    while(1){

        system("cls");
        printf("|------------------ DELETAR ------------------|");
        printf("\n|");
        printf("\n|   Insira o ID do item que deseja apagar: ");
        printf("\n|\t(Digite 0 caso deseje voltar)");
        printf("\n|\n   -> ");
        scanf("%d",&del_id);

        if(del_id == 0){
            menu();
        }//FIM DO IF

        // Aviso de input inválido.
        if(del_id < 0 || del_id > ID){
            system("cls");
            printf("\n|----------- ID NAO ENCONTRADO -----------|\n\n");
            system("pause");
            delete_menu();
        }//FIM DO IF
        
            printf("|---------------------------------------------------|\n|\n");
            printf("|   Id:%d\n", item[del_id-1].id);
            printf("|   Categoria: %s\n", item[del_id-1].category);
            printf("|   Titulo: %s\n", item[del_id-1].title);
            printf("|   Ano: %d\n", item[del_id-1].year);
            printf("|   Nota: %.2f\n", item[del_id-1].rate);
            printf("|\n|   Deseja mesmo deletar este item? ");
            printf("\n|     1-> Sim");
            printf("\n|     2-> Nao");
            printf("\n|\n   -> ");
            scanf("%d",&option);
        

        switch (option){
            case 1:
                delete(del_id); // Função que deletará o item.
                next(); // Perguntará se o usuário deseja fazer a operação novamente, Se sim, o fluxo continua abaixo, se não, volta ao menu().
                delete_menu();
                break;
            
            case 2:
                menu();
                break;

            default:
                // Aviso de input inválido.
                system("cls");
                printf("\n|---------------- OPCAO INVALIDA ----------------|\n\n");
                system("pause");
                break;
        }//FIM DO SWITCH
        
    }//FIM DO WHILE


}//FIM DA FUNÇÂO MENU DE DELETAR ITEM

//FUNÇÃO DE DELETAR ITEM
void delete(int del_id){

    int i, deleted = 0;

    // Decrementa o ID atual
    ID--;

    // Se só tiver um item no catálogo e ele for deletado, o arquivo será deletado também.
    // E o cont(quantidade de itens) será zerado conjuntamente.
    if(ID == 0){
        remove("itens.dat"); 
        cont = 0;
    }
    
    else{
        FILE *arquivo;

        // Abre o arquivo para sobrescrição.
        arquivo = fopen("itens.dat", "w");

        // Percorre todos os itens catalogados.
        for(i = 0; i < cont; i++){

            // Quando ele encontrar o ID do item correspondente ao argumento
            // passado na função, será atribuído o deleted = 1, e o 'for' parte para iteração.
            if(item[i].id == del_id){
                deleted = 1;
                continue;
            }

            // Se o ID não for o que será deletado, o fluxo virá para cá.
            else{

                // Se o ID a ser deletado já foi encontrado, todos os itens seguintes terão ID decrementado.
                if(deleted == 1){
                    item[i].id -=1;
                }
                
                // Se o item não for o primeiro, será efetuada a quebra de linha para separar os itens por linha.
                if(item[i].id != 1){
                    fprintf(arquivo, "\n");
                }

                // Insere o conteúdo do item em uma linha no arquivo.
                fprintf(arquivo, "%d@%s@%s@%d@%f", item[i].id, item[i].category, item[i].title, item[i].year, item[i].rate);
            }
        }
        fclose(arquivo);
        
        // Load data irá atualizar as informações de todos os itens, 'importando' essas informações
        // do arquivo "itens.dat". (Caso não fosse carregado, o item seria deletado do arquivo, mas
        // permaneceria no catálogo dentro do código até ser feita essa 'importação' dos dados).
        load_data();
    }
    
    // Informa ao usuário que o item foi deletado.
    system("cls");
    printf("\n|------------------ ITEM DELETADO COM SUCESSO! ------------------|\n\n");
    system("pause");
    
}//FIM DA FUNÇÃO DE DELETAR ITEM

//FUNCAO PARA REPETIR A FUNCAO OU VOLTA PARA O MENU
void next(){

    int option;

    system("cls");
    printf("|------------------ CONTINUAR ------------------|");
    printf("\n|");
    printf("\n|   Deseja realizar a operacao novamente ? ");
    printf("\n|     1-> Sim");
    printf("\n|     2-> Nao");
    printf("\n|");
    printf("\n|-----------------------------------------------|");
    printf("\n\n   -> ");
    scanf("%d",&option);

    switch (option){
    case 1:
        return;
        break;

    case 2:
        menu();
        break;
    
    default:
        // Aviso de input inválido.
        system("cls");
        printf("\n|---------------- OPCAO INVALIDA ----------------|\n\n");
        system("pause");
        next();
        break;
    }//FIM DO SWITCH

}//FIM DA FUNCAO PARA REPETIR A FUNCAO OU VOLTA PARA O MENU