//#include <iostream>
//#include <algorithm>
//#include <bits/stdc++.h>
//#define MOD 1000000007
//
//using namespace std;
//
//struct Point{
//    int x, y;
//};
//
//struct Point lowestPoint;
//
///*
// 0 - Collinear
// 1 - Clockwise
// 2 - Counter-Clockwise
//*/
//int orientation(struct Point a, struct Point b, struct Point c){
//    int val = (b.y - a.y)*(c.x - b.x) -
//              (c.y - b.y)*(b.x - a.x);
//    if(val==0){
//        return 0;
//    }else{
//        return (val>0)? 1: 2;
//    }
//}
//
//int dist(struct Point &a, struct Point &b){
//     return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
//}
//
//bool compare(struct Point &a, struct Point &b){
//    int o = orientation(lowestPoint, a, b);
//    if(o == 0){
//        return dist(lowestPoint, a)<dist(lowestPoint, b);
//    }else{
//        return (o==2);
//    }
//}
//
//void swapPoint(struct Point &a, struct Point &b){
//    struct Point temp = a;
//    a = b;
//    b = temp;
//}
//
//struct Point stackSecondTop(stack<struct Point> &hull){
//    struct Point t=hull.top();
//    hull.pop();
//    struct Point secondTop = hull.top();
//    hull.push(t);
//    return secondTop;
//}
//
//double distancePoints(struct Point &a, struct Point &b){
//    // Calculating distance
//    return sqrt(pow(b.x - a.x, 2) +
//                pow(b.y - a.y, 2) * 1.0);
//}
//
//stack<Point> findConvexHullBasic(int n){
//    vector<struct Point> inpArr(n);
//    cin>>inpArr[0].x;
//    cin>>inpArr[0].y;
//    int bottomPoint = 0;
//    for(int j=1; j<n; j++){
//        cin>>inpArr[j].x;
//        cin>>inpArr[j].y;
//        if(inpArr[j].y <= inpArr[bottomPoint].y){
//            if(inpArr[j].y <= inpArr[bottomPoint].y){
//                bottomPoint = j;
//            }
//        }
//    }
//
//    swapPoint(inpArr[0], inpArr[bottomPoint]);
//    lowestPoint = inpArr[0];
//    //cout<<"Lowest Point: ("<<lowestPoint.x<<","<<lowestPoint.y<<")"<<endl;
//
//    sort(inpArr.begin()+1, inpArr.end(), compare);
//
//    int finalSize = 1;
//    for(int i=1; i<n; i++){
//        while(i<n-1 && orientation(lowestPoint, inpArr[i], inpArr[i+1])==0)
//            i++;
//        inpArr[finalSize] = inpArr[i];
//        finalSize++;
//    }
//
//    if(finalSize<3){
//        cout<<"Points cannot be <3"<<endl;
//    }
//
//    stack<struct Point> hull;
//    hull.push(lowestPoint);
//    hull.push(inpArr[1]);
//    hull.push(inpArr[2]);
//
//    for(int i=3; i<finalSize; i++){
//        while(orientation(stackSecondTop(hull), hull.top(), inpArr[i])!=2){
//            hull.pop();
//        }
//        hull.push(inpArr[i]);
//    }
//    return hull;
//}
//
//int main(){
//    std::ios::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int n;
//    cin>>n;
//
//    stack<Point> hull = findConvexHullBasic(n);
//
//    struct Point a = hull.top();
//    hull.pop();
//    struct Point b;
//    double perimeter=distancePoints(a, lowestPoint);
//
//    //cout<<"("<<a.x<<","<<a.y<<")"<<endl;
//    while(!hull.empty()){
//        b = hull.top();
//        //cout<<"("<<b.x<<","<<b.y<<")"<<endl;
//        hull.pop();
//        perimeter += distancePoints(a, b);
//        a=b;
//    }
//    cout<<fixed;
//    cout<<setprecision(1);
//    cout<<perimeter<<endl;
//	return 0;
//}
