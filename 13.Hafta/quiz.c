void kayitDegistir(FILE *fp){
    
    int n, m;
    printf("n: "); scanf("%d", &n);
    printf("m: "); scanf("%d", &m);

    struct musteri temp1, temp2;
    // n. sıradaki kaydı okuma
    fseek(fp, sizeof(struct musteri)*(n-1), SEEK_SET);
    fread(&temp1, sizeof(struct musteri), 1, fp);
    // m. sıradaki kaydı okuma
    fseek(fp, sizeof(struct musteri)*(m-1), SEEK_SET);
    fread(&temp2, sizeof(struct musteri), 1, fp);
    // m. sıradaki kaydı n. sıraya yazma
    fseek(fp, sizeof(struct musteri)*(n-1), SEEK_SET);
    fwrite(&temp2, sizeof(struct musteri), 1, fp);
    // n. sıradaki kaydı m. sıraya yazma
    fseek(fp, sizeof(struct musteri)*(m-1), SEEK_SET);
    fwrite(&temp1, sizeof(struct musteri),1 ,fp);
}


