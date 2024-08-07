#include <bits/stdc++.h>

#define int long long
#define double long double
using Pii = std::pair<int, int>;

constexpr double eps = 1e-10;
class Point {
    using Vector = Point;
public:
    double x, y;
    constexpr Point() = default;
    constexpr Point(double X, double Y):x(X),y(Y){}
    constexpr Point(int X, int Y):x(X),y(Y){}
    constexpr friend bool operator< (const Point& a, const Point& b){ return a.x!=b.x?a.x<b.x:a.y<b.y; }
    constexpr friend Point operator+ (const Point& a, const Point& b){ return Point(a.x + b.x, a.y + b.y); }
    constexpr friend Point operator- (const Point& a, const Point& b){ return Point(a.x - b.x, a.y - b.y); }
    constexpr friend Point operator* (const Point& a, double k){ return Point(a.x * k, a.y * k); }
    constexpr friend double operator* (const Point &a, const Point &b) { return Dot(a, b); }
    constexpr friend Point operator/ (const Point& a, double b){ return Point(a.x / b, a.y / b); }  
    constexpr friend double operator^ (const Point &a, const Point &b) { return Cross(a, b); }
    constexpr bool operator== (const Point &other) const { return x == other.x and y == other.y; }
    constexpr bool operator!= (const Point &other) const { return !operator==(other);}
    constexpr Point& operator= (const Point &other) {
        x = other.x, y = other.y;
        return *this;
    }
    constexpr Point& operator= (const std::pair<double, double> &other) {
        x = other.first, y = other.second;
        return *this;
    }
    constexpr static double Length(const Vector &a) { return std::sqrt(Dot(a,a)); }
    constexpr double Length() const { return Length(*this); }
    constexpr static double dcmp(double x){
        if(std::abs(x) < eps) return 0;
        else return x<0?-1:1;
    }
    constexpr static double Dot(const Point &a,const Point &b){ return a.x*b.x+a.y*b.y; }
    constexpr static double Cross(const Point &a,const Point &b){ return a.x*b.y-a.y*b.x; }
    constexpr static double dis(const Point &a, const Point &b){ return std::sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); }
    //求两个向量的夹角（余弦定理）
    constexpr static double Angle(const Vector &a,const Vector &b){ return std::acos(Dot(a,b)/Length(a)/Length(b)); }
    constexpr double Angle(const Point &other) const { return Angle(*this, other); }
    //逆时针旋转rad 
    constexpr static Point Rotate(const Point &a,double rad){ return Point(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad)); }
    constexpr void Rotate(double rad) { *this = Rotate(*this, rad); }
    constexpr static Vector Rotate90Degrees(Vector a) {//旋转90度
        return {-a.y, a.x};
    }
    //求单位长度的法向量 
    constexpr static Point Normal(Point &v){ double L = Length(v); return Point(-v.y/L,v.x/L); }
    constexpr static Point getLineIntersection(const Point &P,const Point &v,const Point &Q,const Point &w){//求两个线段交点 
        Vector u = P-Q;
        double t = Cross(w,u) / Cross(v,w);
        return P + v * t;
    }
    //两线段规范相交、即每条线段的端点分别在另一条一段的两侧 
    constexpr static bool SegmentProperIntersection(const Point &a1,const Point &b1,const Point &a2,const Point &b2){
        double c1=Cross(b1-a1,a2-a1),c2=Cross(b1-a1,b2-a1);
        double c3=Cross(b2-a2,a1-a2),c4=Cross(b2-a2,b1-a2);
        return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
    }
    constexpr static bool IsPointOnSegment(Point &p,Point &a1,Point &a2){//点在线段上 
        return (dcmp(Cross(p-a1,p-a2))==0 && p.x<=std::max(a1.x,a2.x) && p.x>=std::min(a1.x,a2.x)
        && p.y<=std::max(a1.y, a2.y) && p.y>=std::min(a1.y, a2.y));
    }
    constexpr static double getDistToLine(const Point &P, const Point &A, const Point &B){//点到直线的有向距离（存在正负） 
        Vector AB = B - A, AP = P - A;
        return Cross(AB, AP) / Length(AB);
    }
    constexpr static double getDistToSegment(Point &p, Point &a, Point &b){//点到线段的距离
        if (Dot(p - a, b - a) < 0.0) return dis(p, a);
        if (Dot(p - b, a - b) < 0.0) return dis(p, b);
        return std::abs(getDistToLine(p, a, b));
    }
    constexpr static bool isInGeometry(Point &p, std::vector<Point> &v){//点是否在图形内侧
        int flag1 = 0, flag0 = 0;
        int len = v.size();
        for(int i = 0; i < len; ++i){
            double k = Cross(p - v[i], v[(i + 1) % len] - v[i]);
            if(k < 0) ++flag1; // 可以存在边界上的时候取等号
            if(k > 0) ++flag0;
        }
        if(flag1 == v.size() - 1 or flag0 == v.size() - 1) return true;
        else return false; 
    }
    constexpr static Point getCrossPoint(Point a1, Point a2, Point b1, Point b2){//求两直线交点(两点式)
        Vector base = b2 - b1;
        double d1 = abs(Cross(base, a1 - b1));
        double d2 = abs(Cross(base, a2 - b1));
        double t = d1 / (d1 + d2);
        return a1 + (a2 - a1) * t;
    }
    constexpr static Point getCrossPoint1(Point a1, Vector b1, Point a2, Vector b2) {//求两直线交点(点向式)
        double t = Cross(a2 - a1, b2) / Cross(b1, b2);
        return a1 + b1 * t;
    }
    constexpr static double Ploygon_area(std::vector<Point> &s){// 求多边形面积(Shoelace Theorem，鞋带定理)
        int n = s.size();
        double ans = 0.0;
        for (int i = 0; i < n; i++){
            ans += Cross(s[i], s[(i + 1) % n]);
        }
        return ans * 0.5;
    }

    constexpr static Point project(Point &p, Point &a, Point &b){//求点P在直线s上的投影
        Vector base = b - a;
        double r = Dot(p - a, base) / (base.x*base.x + base.y*base.y);
        base = base * r;
        return Point(a + base);
    }

    constexpr static Point reflect(Point p, Point a, Point b){//求点P对于直线s的映像(对称点)
        return p + (project(p, a, b) - p) * 2.0;
    }
    //O(nlogn)求凸包,凸包顶点放在ch中,逆时针
    constexpr static std::vector<Point> getConvexHull(std::vector<Point> &points) {
        auto p = points;
        if(!std::is_sorted(p.begin(), p.end())) std::sort(p.begin(), p.end());
        p.erase(std::unique(p.begin(), p.end()), p.end());
        std::vector<Point> ch;
        for (int i = 0; i < p.size(); i++) {
            while (ch.size() >= 2 && ((ch[ch.size() - 1] - ch[ch.size() - 2]) ^ (p[i] - ch[ch.size() - 2])) < eps) ch.pop_back();
            ch.push_back(p[i]);
        }
        int j = ch.size();
        for (int i = p.size() - 2; i >= 0; i--) {
            while (ch.size() > j && ((ch[ch.size() - 1] - ch[ch.size() - 2]) ^ (p[i] - ch[ch.size() - 2])) < eps) ch.pop_back();
            ch.push_back(p[i]);
        }
        ch.pop_back();
        return ch;
    }
};



const double PI = acos(-1);

double rotate(std::vector<Point> &a, double rad) {
    double mn = 1e30, mx = -1e30;
    rad = PI / 2 - rad;
    for(auto i:a) {
        Point x = Point::Rotate(i, rad);
        mn = std::min(x.x, mn);
        mx = std::max(x.x, mx);
    }
    return mx - mn;
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, v0, v1, v2;
    std::cin >> n >> v0 >> v1 >> v2;
    std::vector<Point> a(n);
    for(int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        a[i] = Point{x, y};
    }
    if(n == 1) {
        printf("%.10Lf\n", (double)0);
        return 0;
    }
    std::sort(a.begin(), a.end());

    auto list = Point::getConvexHull(a);
    list.push_back(list.front());
    int mxdis = 1;
    double l = (double)v0 / v1, r = (double)v0 / v2;
    if(r < l) std::swap(l, r);
    double ans = 1e30;
    if(list.size() == 2) {
        printf("%.10Lf\n", (double)0);
        return 0;
    }
    if(list.size() <= 2) goto A;
    for(int i = 1; i < (int)list.size(); ++i) {
        auto &p1 = list[i], &p2 = list[i - 1];
        double k = (p1.y - p2.y) / (p1.x - p2.x);
        while(1) {
            int next = (mxdis + 1) % (list.size() - 1);
            if(std::abs(Point::getDistToLine(list[next], list[i], list[i - 1])) <= std::abs(Point::getDistToLine(list[mxdis], list[i], list[i - 1]))) {
                break;
            }
            mxdis = next;
        }
        if(!(k >= l and k <= r)) continue;
        ans = std::min(ans, std::abs(Point::getDistToLine(list[mxdis], list[i], list[i - 1])));
    }
    A:;
    ans = std::min(ans, rotate(a, atan(l))); 
    ans = std::min(ans, rotate(a, atan(r))); 

    printf("%.10Lf\n", ans);

    return 0;
}