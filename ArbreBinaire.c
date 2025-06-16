#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noeud {
    int valeur;
    struct noeud* filsgauche;
    struct noeud* filsdroit;
    int hauteur;
} noeud;

typedef noeud* arbre;

noeud* nouveaunoeud(int x) {
    noeud* r = (noeud*)malloc(sizeof(noeud));
    r->valeur = x;
    r->filsgauche = NULL;
    r->filsdroit = NULL;
    return r;
}

bool estFeuille(noeud* r) {
    return r != NULL && r->filsdroit == NULL && r->filsgauche == NULL;
}

int nbFeuille(noeud* r) {
    if (r == NULL)
        return 0;
    else if (estFeuille(r))
        return 1;
    else
        return nbFeuille(r->filsgauche) + nbFeuille(r->filsdroit);
}

int nbNoeud(noeud* r) {
    if (r == NULL)
        return 0;
    else
        return nbNoeud(r->filsgauche) + nbNoeud(r->filsdroit) + 1;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int hauteur(noeud* r) {
    if (r == NULL)
        return -1;
    else
        return max(hauteur(r->filsgauche), hauteur(r->filsdroit)) + 1;
}

void insererABR(noeud** r, int x) {
    if (*r == NULL) {
        *r = nouveaunoeud(x);
    } else {
        if (x < (*r)->valeur)
            insererABR(&((*r)->filsgauche), x);
        else if (x > (*r)->valeur)
            insererABR(&((*r)->filsdroit), x);
        // Nếu bằng thì không chèn (tránh trùng lặp)
    }
}

void parcoursPrefixe(noeud* r) { // goc-trai-phai
    if (r != NULL) {
        printf("%d ", r->valeur);
        parcoursPrefixe(r->filsgauche);
        parcoursPrefixe(r->filsdroit);
    }
}

void parcoursInfixe(noeud* r) { // trai-goc-phai
    if (r != NULL) {
        parcoursPrefixe(r->filsgauche);
        printf("%d ", r->valeur);
        parcoursPrefixe(r->filsdroit);
    }
}

void parcoursPostfixe(noeud* r) { // trai phai goc
    if (r != NULL) {
        parcoursPrefixe(r->filsgauche);
        parcoursPrefixe(r->filsdroit);
        printf("%d ", r->valeur);
    }
}

// chercher un element dans quelques arbres
noeud* rechercheElement(noeud* r, int x){
    if (r != NULL) {
        if (r->valeur == x)
            return r;
        noeud* res = rechercheElement(r->filsgauche, x);
        if (res == NULL)
            res = rechercheElement(r->filsdroit, x);
        return res;
    }
    return NULL;
}

noeud* rechercheABR(noeud* r, int x){
    if (r == NULL || r->valeur == x)
        return r;
    if (x < r->valeur)
        return rechercheABR(r->filsgauche, x);
    else
        return rechercheABR(r->filsdroit, x);
}

noeud* rechercheMinimum(noeud* r){
    if(r != NULL){
        if(r->filsgauche != NULL){
            r = rechercheMinimum(r->filsgauche);
        }
    }
    return r;
}

noeud* rechercheMaximum(noeud* r){
    if(r != NULL){
        if(r->filsdroit != NULL){
            r = rechercheMaximum(r->filsdroit);
        }
    }
    return r;
}

// rechercher le predecesseur nut lon nhat trong cac nut nho hon
noeud* recherchePredecesseurABR(noeud *r, int x){
    if (r != NULL){
        if (r->valeur >= x){
            recherchePredecesseurABR(r->filsgauche, x);
        } else {
            noeud* rd;
            rd= recherchePredecesseurABR(r->filsdroit, x);
            if (rd != NULL){
                r=rd;
            }
        }
    }
    return r;
}

// nut nho nhat trong cac nut lon hon
noeud* rechercheSuccesseurABR(noeud *r, int x){
    if (r != NULL){
        if (r->valeur <= x){
            rechercheSuccesseurABR(r->filsdroit, x);
        } else {
            noeud* rd;
            rd= rechercheSuccesseurABR(r->filsgauche, x);
            if (rd != NULL){
                r=rd;
            }
        }
    }
    return r;
}

// tim va tra ve nut nho nhat trong cay con goc r
// dong thoi xoa nut nay khoi cay bang cach noi lai cay
noeud* extraireMnimumABR(noeud* r){
    if (r->filsgauche == NULL){
        noeud* m = r;
        r = r->filsdroit; // on supprime le minimum
        return m; // puis on le renvoie 
    } else {
        return extraireMnimumABR(r->filsgauche);
    }
}
/*
        5
       / \
      3   7
     /   / \
    2   6   8
   /
  1 
  di tu 5-3-2-1 ( vi 1.filsgauche == null)
  tra ve 1 va cap nhap 2.filsgauche == null
*/
void supprimerElementABR(noeud* r, int x){
    if(r == NULL){
        // ne rien faire
    } else {
        if(x < r->valeur){
            supprimerElementABR(r->filsgauche, x);
        } else if (x>r->valeur){
            supprimerElementABR(r->filsdroit,x);
        } else { // x=r.valeur
            if(r->filsgauche == NULL){
                r=r->filsdroit;
            } else if(r->filsdroit == NULL){
                r= r->filsgauche;
            } else {
                noeud* m;
                m = extraireMnimumABR(r->filsdroit);
                m->filsgauche = r->filsgauche;
                m->filsdroit = r->filsdroit;
                r=m;
            }
        }
    }
}
/*
        5
       / \
      3   7
     /   / \
    2   6   8                    
   /
  1

  xoa nut 5

        6
       / \
      3   7
     /     \
    2       8
   /
  1
*/



// ARBRE EQUILIBRE 

// Cập nhật lại chiều cao của nút
void mettreAJourHauteur(noeud* n) {
    if (n == NULL) return;
    n->hauteur = 1 + max(hauteur(n->filsgauche), hauteur(n->filsdroit));
}

// Tính hệ số cân bằng (Balance Factor)
int balanceFactor(noeud* n) {
    if (n == NULL) return 0;
    return hauteur(n->filsgauche) - hauteur(n->filsdroit);
}
// ham quay phaiphai
noeud* rotationDroite(noeud* y) {
    noeud* x = y->filsgauche;
    noeud* T2 = x->filsdroit;

    // Thực hiện quay phải
    x->filsdroit = y;
    y->filsgauche = T2;

    // Cập nhật chiều cao
    mettreAJourHauteur(y);
    mettreAJourHauteur(x);
    
    return x;  // Nút mới thay thế vị trí y
}

// ham quay trai 
noeud* rotationGauche(noeud* x) {
    noeud* y = x->filsdroit;
    noeud* T2 = y->filsgauche;

    // Thực hiện quay trái
    y->filsgauche = x;
    x->filsdroit = T2;

    // Cập nhật chiều cao
    mettreAJourHauteur(x);
    mettreAJourHauteur(y);

    return y;  // Nút mới thay thế vị trí x
}

// ham chen voi tu can bang avl
noeud* insererAVL(noeud* n, int valeur) {
    // 1. Chèn như cây BST thông thường
    if (n == NULL)
        return nouveaunoeud(valeur);

    if (valeur < n->valeur)
        n->filsgauche = insererAVL(n->filsgauche, valeur);
    else if (valeur > n->valeur)
        n->filsdroit = insererAVL(n->filsdroit, valeur);
    else // Không cho phép giá trị trùng
        return n;

    // 2. Cập nhật chiều cao của nút hiện tại
    mettreAJourHauteur(n);

    // 3. Kiểm tra hệ số cân bằng
    int balance = balanceFactor(n);

    // 4. Xử lý 4 trường hợp mất cân bằng

    // Trường hợp Left Left
    if (balance > 1 && valeur < n->filsgauche->valeur)
        return rotationDroite(n);

    // Trường hợp Right Right
    if (balance < -1 && valeur > n->filsdroit->valeur)
        return rotationGauche(n);

    // Trường hợp Left Right
    if (balance > 1 && valeur > n->filsgauche->valeur) {
        n->filsgauche = rotationGauche(n->filsgauche);
        return rotationDroite(n);
    }

    // Trường hợp Right Left
    if (balance < -1 && valeur < n->filsdroit->valeur) {
        n->filsdroit = rotationDroite(n->filsdroit);
        return rotationGauche(n);
    }

    return n;
}

// ham xoa voi tu can bang avl 
noeud* supprimerAVL(noeud* racine, int valeur) {
    // Bước 1: Xóa như BST thông thường
    if (racine == NULL)
        return racine;

    if (valeur < racine->valeur)
        racine->filsgauche = supprimerAVL(racine->filsgauche, valeur);
    else if (valeur > racine->valeur)
        racine->filsdroit = supprimerAVL(racine->filsdroit, valeur);
    else {
        // Nút có một con hoặc không có con
        if ((racine->filsgauche == NULL) || (racine->filsdroit == NULL)) {
            noeud* temp = racine->filsgauche ? racine->filsgauche : racine->filsdroit;

            // Trường hợp không có con
            if (temp == NULL) {
                temp = racine;
                racine = NULL;
            } else // Trường hợp có một con
                *racine = *temp; // Copy nội dung của con

            free(temp);
        } else {
            // Nút có hai con: lấy nút nhỏ nhất bên phải
            noeud* temp = rechercheMinimum(racine->filsdroit);
            racine->valeur = temp->valeur;
            racine->filsdroit = supprimerAVL(racine->filsdroit, temp->valeur);
        }
    }

    // Nếu cây chỉ có một nút thì return
    if (racine == NULL)
        return racine;

    // Bước 2: Cập nhật chiều cao
    mettreAJourHauteur(racine);

    // Bước 3: Kiểm tra cân bằng
    int balance = balanceFactor(racine);

    // Bước 4: Cân bằng cây (tương tự khi chèn)
    // Left Left
    if (balance > 1 && balanceFactor(racine->filsgauche) >= 0)
        return rotationDroite(racine);

    // Left Right
    if (balance > 1 && balanceFactor(racine->filsgauche) < 0) {
        racine->filsgauche = rotationGauche(racine->filsgauche);
        return rotationDroite(racine);
    }

    // Right Right
    if (balance < -1 && balanceFactor(racine->filsdroit) <= 0)
        return rotationGauche(racine);

    // Right Left
    if (balance < -1 && balanceFactor(racine->filsdroit) > 0) {
        racine->filsdroit = rotationDroite(racine->filsdroit);
        return rotationGauche(racine);
    }

    return racine;
}

// Kiểm tra và cân bằng cây
noeud* equilibrer(noeud* n) {
    int balance = balanceFactor(n);
    // Left Left Case
    if (balance > 1 && balanceFactor(n->filsgauche) >= 0)
        return rotationDroite(n);
    // Right Right Case
    if (balance < -1 && balanceFactor(n->filsdroit) <= 0)
        return rotationGauche(n);
    // Left Right Case
    if (balance > 1 && balanceFactor(n->filsgauche) < 0) {
        n->filsgauche = rotationGauche(n->filsgauche);
        return rotationDroite(n);
    }
    // Right Left Case
    if (balance < -1 && balanceFactor(n->filsdroit) > 0) {
        n->filsdroit = rotationDroite(n->filsdroit);
        return rotationGauche(n);
    }
    
    return n;
}
// Bài Toán Chèn/Xóa với Tự Cân Bằng
// bai toan tim kiemkiem
noeud* rechercheAVL(noeud* racine, int valeur) {
    if (racine == NULL || racine->valeur == valeur)
        return racine;
    
    if (valeur < racine->valeur)
        return rechercheAVL(racine->filsgauche, valeur);
    else
        return rechercheAVL(racine->filsdroit, valeur);
}

int Abs11(int a, int b){
    if (a>b){
        return a-b;
    } else {
        return b-a;
    }
}
bool estAVL(noeud* r) {
    if (r == NULL) {
        return true; // Cây rỗng là AVL
    }
    int hd = hauteur(r->filsdroit);
    int hg = hauteur(r->filsgauche);

    if (Abs11(hd, hg) >= 2) {
        return false; // Mất cân bằng
    }

    // Đệ quy kiểm tra hai cây con cũng phải là AVL
    return estAVL(r->filsdroit) && estAVL(r->filsgauche);
}
int main() {
    arbre monArbre = NULL;

    insererABR(&monArbre, 50);
    insererABR(&monArbre, 30);
    insererABR(&monArbre, 70);
    insererABR(&monArbre, 20);
    insererABR(&monArbre, 40);
    insererABR(&monArbre, 60);
    insererABR(&monArbre, 80);

    printf("Parcours prefixe: ");// goc trai phai
    parcoursPrefixe(monArbre);  // Kết quả: 50 30 20 40 70 60 80
    printf("\n");
    printf("Parcours infixe: "); // trai goc phai
    parcoursInfixe(monArbre);  // Kq: 30 20 40 50 70 60 80
    printf("\n");
    printf("Parcours prefixe: ");// trai phai goc
    parcoursPostfixe(monArbre);  // Kq: 30 20 40 70 60 80 50
    printf("\n");
    printf("\nNombre de feuilles: %d\n", nbFeuille(monArbre));   // 4
    printf("Nombre de noeuds: %d\n", nbNoeud(monArbre));         // 7
    printf("Hauteur de l'arbre: %d\n", hauteur(monArbre));       // 2

    noeud* f =rechercheElement(monArbre, 10);
    if (f!=NULL){
        printf("trouve : %d \n", f->valeur);
    } else {
        printf("ne pas trouve \n");
    }

    noeud* x = rechercheMinimum(monArbre);
    printf("element minimum est %d \n", x->valeur); // 20

    noeud* y = rechercheMaximum(monArbre);
    printf("element maximal est %d \n", y->valeur); //80

    noeud* z=recherchePredecesseurABR(monArbre, 90);
    printf("le predesseur de 90 est %d \n", z->valeur); // 80

    noeud* t=rechercheSuccesseurABR(monArbre, 30);
    printf("le predesseur de 30 est %d \n", t->valeur);


    return 0;
}
