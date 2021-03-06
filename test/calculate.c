#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("orig.txt", "r");
    FILE *output = fopen("output.txt", "w");
    if (!fp) {
        printf("ERROR opening input file orig.txt\n");
        exit(0);
    }
    int i = 0;
    char append[50], find[50];
    double orig_sum_a = 0.0, orig_sum_f = 0.0, orig_a, orig_f;
    for (i = 0; i < 1; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &orig_a, &orig_f);
        orig_sum_a += orig_a;
        orig_sum_f += orig_f;
    }
    fclose(fp);

    fp = fopen("opt.txt", "r");
    if (!fp) {
        fp = fopen("orig.txt", "r");
        if (!fp) {
            printf("ERROR opening input file opt.txt\n");
            exit(0);
        }
    }
    double opt_sum_a = 0.0, opt_sum_f = 0.0, opt_a, opt_f;
    for (i = 0; i < 1; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &opt_a, &opt_f);
        opt_sum_a += opt_a;
        opt_sum_f += opt_f;
    }
    fclose(fp);

    fp = fopen("bptree.txt","r");
    if (!fp) {
        fp = fopen("orig.txt", "r");
        if (!fp) {
            printf("ERROR opening input file bptree.txt\n");
            exit(0);
        }
    }
    double bptree_sum_a = 0.0, bptree_sum_f = 0.0, bptree_a, bptree_f;
    for (i = 0; i < 1; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 10 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &bptree_a, &bptree_f);
        bptree_sum_a += bptree_a;
        bptree_sum_f += bptree_f;
    }
    fclose(fp);

    fp = fopen("bulk.txt","r");
    if (!fp) {
        fp = fopen("orig.txt", "r");
        if (!fp) {
            printf("ERROR opening input file bulk.txt\n");
            exit(0);
        }
    }
    double bulk_sum_a = 0.0, bulk_sum_f = 0.0, bulk_a, bulk_f;
    for (i = 0; i < 1; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 10 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &bulk_a, &bulk_f);
        bulk_sum_a += bulk_a;
        bulk_sum_f += bulk_f;
    }
    fclose(fp);

    fprintf(output, "append() %lf %lf %lf %lf\n",orig_sum_a / 1.0, opt_sum_a / 1.0, bptree_sum_a/1.0, bulk_sum_a/1.0);
    fprintf(output, "findName() %lf %lf %lf %lf", orig_sum_f / 1.0, opt_sum_f / 1.0, bptree_sum_f/1.0, bulk_sum_f/1.0);
    fclose(output);
    return 0;
}
