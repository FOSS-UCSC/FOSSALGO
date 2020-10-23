#include<stdio.h>
#include<inttypes.h>
#include<math.h>
#include<stdlib.h>
typedef struct{
    float x;
    float y;
    int_fast8_t class_or_value;
}Point;
static float *distance = NULL;
static unsigned k;
static int_fast8_t *class_count = NULL;
// utility function to calculate distance between two points using Euclidean Distance Method
float get_euclidean_distance(const Point p, const Point q){
    return sqrtf((p.x - q.x) * (p.x - q.x) + (p.y-q.y) * (p.y-q.y));
}
// update class or point values in training set
// can be used for both regressor and classifier
void assign_classes(Point training_set[], const int_fast8_t classes[], const size_t size){
    for(int i = 0; i < (int)size; ++i){
        training_set[i].class_or_value = classes[i];
    }   
}
// calculate distance between each given point and test point
void update_distance(const Point training_set[], const size_t size,const Point q){
    distance = (float *)malloc(size * sizeof(float));
    for(int i = 0; i < (int)size; ++i){
        distance[i] = get_euclidean_distance(training_set[i], q); 
    }
}
// utility function for swapping elements in collection
void swap(Point *a, Point *b){
    Point temp = {.x = a->x,.y=a->y,.class_or_value=a->class_or_value};
    a->x = b->x;
    a->y = b->y;
    a->class_or_value = b->class_or_value;
    b->x = temp.x;
    b->y = temp.y;
    b->class_or_value = temp.class_or_value;
}
// sort distance as well as training set in the non-decreasing order of distance values.
void sort_distance(float * restrict distance,Point * restrict training_set,const size_t size){
    for(int i=0;i<(int)size;++i){
        for(int j=i+1;j<(int)size;++j){
            if(distance[i]<distance[j]){
                // swap(&distance[i], &distance[j]);
                swap(&training_set[i], &training_set[j]);
            }
        }
    }
    free(distance);
}
// updating the array 
void update_class_score(const Point training_set[],const size_t size,const unsigned k){
    if(k<=(unsigned)size){
        class_count = (int_fast8_t *)malloc(size*sizeof(int_fast8_t));
        for(int i=0;i<(int)size;++i){
            class_count[i]=0;
        }
        for(int i=0;i<k;++i){
            class_count[training_set[i].class_or_value]++;

        }
    }
}
Point knn_classifier(Point *X, /* Training Set */
                            int_fast8_t *y, /* Class Labels */
                            size_t size, /* Training Set Size */
                            Point p, /* Test Point */
                            int k) /* K-means variable value */
{
    assign_classes(X,y,size);
    update_distance(X,size,p);
    sort_distance(distance,X,size); // global distance
    update_class_score(X,size,k);
    int_fast8_t max_score = -1;
    int_fast8_t index = 0;
    for(int i = 0; i < (int)size; ++i){
        if(class_count[i] > max_score){
            max_score = class_count[i];
            index = i;
        }
    }
    free(class_count);
    p.class_or_value = index;
    return p;
}
Point knn_regressor(Point *X, /* Training Set */
                            int_fast8_t *y, /* Class Labels */
                            size_t size, /* Training Set Size */
                            Point p, /* Test Point */
                            int k) /* K-means variable value */
{
    assign_classes(X,y,size);
    update_distance(X,size,p);
    sort_distance(distance,X,size); // global distance
    int_fast8_t avg = 0;
    for(int i = 0; i < k; ++i){
        avg += X[i].class_or_value;
    }
    avg = avg / k;
    p.class_or_value = avg;
    return p;
}

int main(void){
    Point p[] = {
{.x=40000,.y=25},
{.x=60000,.y=35},
{.x=80000,.y=45},
{.x=20000,.y=20},
{.x=120000, .y=35},
{.x=18000,.y=52},
{.x=95000,.y=23},
{.x=62000,.y=40},
{.x=100000,.y=60},
{.x=220000,.y=48},
{.x=150000,.y=33}
};
int_fast8_t c[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
Point q = {.x=142000,.y=48};
int k = 2;
q = knn_classifier(p,c,sizeof(c)/sizeof(int_fast8_t),q,k);
printf("The class belongs to %d",q.class_or_value);
    return 0;
}