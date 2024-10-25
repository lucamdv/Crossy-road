#include "menu.h"
#include <stdio.h>
#include <string.h>
#include "screen.h"
#include "keyboard.h"

int current_option = 0; // Posição atual no menu
char *menu_items[] = {
    "Enter - Iniciar Jogo",
    "Esc - Sair"
};
int total_menu_items = 2;

// Função que exibe o menu principal com o título "Crossy Road"
void display_menu() {
    screenClear();

    // Exibir o título "Crossy Road" centralizado
    char *title = "Crossy Road";
    int title_length = strlen(title);
    int title_startX = (WIDTH - title_length) / 2; // Centralizar o título horizontalmente
    int title_startY = 8; // Posição vertical do título

    // Exibe o título com uma fonte maior
    screenSetColor(YELLOW, DARKGRAY);
    screenGotoxy(title_startX, title_startY);
    printf("%s", title);

    // Exibir as opções do menu centralizadas abaixo do título
    int startX = (WIDTH - strlen(menu_items[0])) / 2; // Centralizar os itens do menu horizontalmente
    int startY = 12; // Posição vertical dos itens do menu
    
    for (int i = 0; i < total_menu_items; i++) {
        screenGotoxy(startX, startY + i);
        if (i == current_option) {
            screenSetColor(RED, DARKGRAY); // Destacar a opção selecionada
        } else {
            screenSetColor(CYAN, DARKGRAY); // Cor padrão para outros itens
        }
        printf("%s", menu_items[i]);
    }

    // Atualizar a tela
    screenUpdate();
}

// Função que navega entre os itens do menu
void handle_menu_input(char ch) {
    if (ch == 'w' && current_option > 0) { // Sobe no menu
        current_option--;
    } else if (ch == 's' && current_option < total_menu_items - 1) { // Desce no menu
        current_option++;
    }
}