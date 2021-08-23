#define _MAT22

#ifdef _MAT22
#include"libOne.h"

//‚QŽŸŒ³ƒxƒNƒgƒ‹i‚Qs‚P—ñ‚Ìs—ñ‚Æ‚µ‚Äl‚¦‚é‚±‚Æ‚à‚Å‚«‚éj
class VEC {
public:
    //s—ñ‚Ì—v‘f
    float x;
    float y;
    //ƒRƒ“ƒXƒgƒ‰ƒNƒ^
    VEC(float x = 0, float y = 0) {
        this->x = x;
        this->y = y;
    }
};

//‚Qs‚Q—ñ‚Ìs—ñ
class MAT22 {
public:
    //s—ñ‚Ì—v‘f
    float _11, _12;
    float _21, _22;
    //ƒRƒ“ƒXƒgƒ‰ƒNƒ^
    MAT22(float _11, float _12,
          float _21, float _22 ) {
        this->_11 = _11; this->_12 = _12;
        this->_21 = _21; this->_22 = _22;
    }
    MAT22() {
        identity();
    }
    //’PˆÊs—ñ‚ð‚Â‚­‚é
    void identity() {
        _11 = 1; _12 = 0;
        _21 = 0; _22 = 1;
    }
    //Šg‘åk¬s—ñ‚ð‚Â‚­‚é
    void scaling(float sx, float sy) {
        _11 = sx;
        _22 = sy;
    }
    //‰ñ“]s—ñ‚ð‚Â‚­‚é
    void rotate(float angle) {
        float c = cos(angle);
        float s = sin(angle);
        _11 = c; _12 = -s;
        _21 = s; _22 = c;
    }
    //u‚Qs‚Q—ñs—ñv‚Æu‚Qs‚P—ñs—ñi‚QŽŸŒ³ƒxƒNƒgƒ‹jv‚ÌŠ|‚¯ŽZ
    VEC operator*(const VEC& v) {
        return VEC(
            _11 * v.x + _12 * v.y,
            _21 * v.x + _22 * v.y
        );
    }
    //‚Qs‚Q—ñs—ñ‚Ç‚¤‚µ‚ÌŠ|‚¯ŽZ
    MAT22 operator*(const MAT22& m) {
        return MAT22(
            _11 * m._11 + _12 * m._21,//‚Ps‚P—ñ‚Ì—v‘f
            _11 * m._12 + _12 * m._22,//‚Ps‚Q—ñ‚Ì—v‘f

            _21 * m._11 + _22 * m._21,//‚Qs‚P—ñ‚Ì—v‘f
            _21 * m._12 + _22 * m._22 //‚Qs‚Q—ñ‚Ì—v‘f
        );
    }
};

//”wŒiƒNƒŠƒAŠÖ”
void background() {
    fill(0, 0, 60); noStroke(); rect(0, 0, width, height);
}

//u‚P‚Â‚ÌÀ•Wv‚ðu‚Qs‚Q—ñ‚Ìs—ñ‚Å‰ñ“]AŠg‘åk¬‚·‚év
void gmain() {
    window(1080, 1080, full);
    hideCursor();
    
    angleMode(DEGREES);
    colorMode(HSV);
    COLOR c(60, 128, 255);

    VEC op(0.86f, 0.5f);//original position
    VEC p;//s—ñŒvŽZŒã‚Ìposition
    
    MAT22 rm;//rotate matrix
    MAT22 sm;//scaling matrix
    
    float angle = 0;

    while (notQuit) {
        background();
        mathAxis(2, 128);
        //s—ñ‚ð‚Â‚­‚é
        rm.rotate(angle);
        sm.scaling(0.6f, 0.6f);
        MAT22 m = sm * rm;
        angle += 1;
        //À•W•ÏŠ·‚·‚é
        p = m * op;
        //•`‰æ
        strokeWeight(20);
        stroke(c);
        //Œ³‚ÌÀ•W
        mathPoint(op.x, op.y);
        //•ÔŠÒŒã‚ÌÀ•W
        mathPoint(p.x, p.y);
    }
}
#endif

#ifdef _MAT33
#include"libOne.h"
class VEC {
public:
    float x, y;
    VEC(float x = 0, float y = 0) {
        this->x = x;
        this->y = y;
    }
};
class MAT33 {
public:
    float _11, _12, _13;
    float _21, _22, _23;
    float _31, _32, _33;
    MAT33(float _11, float _12, float _13,
        float _21, float _22, float _23,
        float _31, float _32, float _33) {
        this->_11 = _11; this->_12 = _12; this->_13 = _13;
        this->_21 = _21; this->_22 = _22; this->_23 = _23;
        this->_31 = _31; this->_32 = _32; this->_33 = _33;
    }
    MAT33() {
        identity();
    }
    void identity() {
        _11 = 1; _12 = 0; _13 = 0;
        _21 = 0; _22 = 1; _23 = 0;
        _31 = 0; _32 = 0; _33 = 1;
    }
    void scaling(float sx, float sy) {
        _11 = sx;
        _22 = sy;
    }
    void rotate(float angle) {
        float c = cos(angle);
        float s = sin(angle);
        _11 = c; _12 = -s;
        _21 = s; _22 = c;
    }
    void translate(float x, float y) {
        _13 = x;
        _23 = y;
    }
    VEC operator*(const VEC& v) {
        return VEC(
            _11 * v.x + _12 * v.y + _13 * 1,
            _21 * v.x + _22 * v.y + _23 * 1
        );
    }
    MAT33 operator*(const MAT33& m) {
        return MAT33(
            _11 * m._11 + _12 * m._21 + _13 * m._31,
            _11 * m._12 + _12 * m._22 + _13 * m._32,
            _11 * m._13 + _12 * m._23 + _13 * m._33,
            _21 * m._11 + _22 * m._21 + _23 * m._31,
            _21 * m._12 + _22 * m._22 + _23 * m._32,
            _21 * m._13 + _22 * m._23 + _23 * m._33,
            _31 + m._11 + _32 * m._21 + _33 * m._31,
            _31 + m._12 + _32 * m._22 + _33 * m._32,
            _31 + m._13 + _32 * m._23 + _33 * m._33
        );
    }
};

#include<vector>
void background() {
    fill(0, 0, 60); noStroke(); rect(0, 0, width, height);
}
void gmain() {
    window(1080, 1080, full);
    hideCursor();
    angleMode(DEGREES);
    colorMode(HSV);
    float satu = 128;
    float bright = 255;
    std::vector<COLOR> c;
    std::vector<VEC> ops;
    int num = 8;
    float angle = 360.0f / num;
    for (int i = 0; i < num; i++) {
        ops.emplace_back(sin(angle * i), cos(angle * i));
        c.emplace_back(angle * i, satu, bright);
    }
    std::vector<VEC> ps;
    MAT33 tm, rm, sm;
    angle = 0;
    while (notQuit) {
        background();
        //axisMode(NODRAW);
        mathAxis(3, 128);

        rm.rotate(angle);
        tm.translate(1, 0);
        sm.scaling(0.4f, 0.4f);
        MAT33 m = rm * tm * rm * sm;
        angle += 1;

        ps = ops;
        for (VEC& pt : ps) {
            pt = m * pt;
        }

        for (int i = 0; i < ps.size(); i++) {
            strokeWeight(10);
            stroke(c[i]);
            //mathPoint(ops[i].x, ops[i].y);
            mathPoint(ps[i].x, ps[i].y);
            int j = (i + 1) % ps.size();
            //mathLine(ps[i].x, ps[i].y, ps[j].x, ps[j].y);
        }
    }
}
#endif

#ifdef _MAT33_OPT
#include"libOne.h"
class VEC {
public:
    float x, y;
    VEC(float x = 0, float y = 0) {
        this->x = x;
        this->y = y;
    }
};
class MAT33 {
public:
    float _11, _12, _13;
    float _21, _22, _23;
    //float _31, _32, _33;
    MAT33(float _11, float _12, float _13,
        float _21, float _22, float _23
        //,float _31, float _32, float _33
    ) {
        this->_11 = _11; this->_12 = _12; this->_13 = _13;
        this->_21 = _21; this->_22 = _22; this->_23 = _23;
        //this->_31 = _31; this->_32 = _32; this->_33 = _33;
    }
    MAT33() {
        identity();
    }
    void identity() {
        _11 = 1; _12 = 0; _13 = 0;
        _21 = 0; _22 = 1; _23 = 0;
        //_31 = 0; _32 = 0; _33 = 1;
    }
    void scaling(float sx, float sy) {
        _11 = sx;
        _22 = sy;
    }
    void rotate(float angle) {
        float c = cos(angle);
        float s = sin(angle);
        _11 = c; _12 = -s;
        _21 = s; _22 = c;
    }
    void translate(float x, float y) {
        _13 = x;
        _23 = y;
    }
    VEC operator*(const VEC& v) {
        return VEC(
            _11 * v.x + _12 * v.y + _13 * 1,
            _21 * v.x + _22 * v.y + _23 * 1
        );
    }
    MAT33 operator*(const MAT33& m) {
        return MAT33(
            _11 * m._11 + _12 * m._21,// + _13 * m._31,
            _11 * m._12 + _12 * m._22,// + _13 * m._32,
            _11 * m._13 + _12 * m._23 + _13,// * m._33,

            _21 * m._11 + _22 * m._21,// +_23 * m._31,
            _21 * m._12 + _22 * m._22,// + _23 * m._32,
            _21 * m._13 + _22 * m._23 + _23// * m._33
            //,_31 + m._11 + _32 * m._21 + _33 * m._31,
            //_31 + m._12 + _32 * m._22 + _33 * m._32,
            //_31 + m._13 + _32 * m._23 + _33 * m._33
        );
    }
};

#include<vector>
void background() {
    fill(0, 0, 20); noStroke(); rect(0, 0, width, height);
}
void gmain() {
    window(1080, 1080, full);
    hideCursor();
    angleMode(DEGREES);
    colorMode(HSV);
    float satu = 128;
    float bright = 255;
    std::vector<COLOR> c;
    std::vector<VEC> ops;
    int num = 10;
    float angle = 360.0f / num;
    for (int i = 0; i < num; i++) {
        float r = 0.5f + 0.5f * !(i % 2);
        ops.emplace_back(sin(angle * i) * r, cos(angle * i) * r);
        c.emplace_back(angle * i, satu, bright);
    }
    std::vector<VEC> ps;
    MAT33 tm, rm, sm, rm2;
    angle = 0;
    while (notQuit) {
        background();
        axisMode(NODRAW);
        mathAxis(2, 128);

        rm2.rotate(angle);
        tm.translate(1, 0);
        rm.rotate(angle * 4);
        sm.scaling(0.25f, 0.5f);
        angle += 0.5f;
        MAT33 m = rm2 * tm * sm * rm;

        ps = ops;
        for (VEC& pt : ps) {
            pt = m * pt;
        }

        for (int i = 0; i < ps.size(); i++) {
            strokeWeight(10);
            stroke(c[i]);
            //mathPoint(ops[i].x, ops[i].y);
            mathPoint(ps[i].x, ps[i].y);
            int j = (i + 1) % ps.size();
            mathLine(ps[i].x, ps[i].y, ps[j].x, ps[j].y);
        }
    }
}
#endif

#ifdef _MAT33_EXPLAIN
#include"libOne.h"
class VEC {
public:
    float x, y;
    VEC(float x = 0, float y = 0) {
        this->x = x;
        this->y = y;
    }
};
class MAT33 {
public:
    float _11, _12, _13;
    float _21, _22, _23;
    //float _31, _32, _33;
    MAT33(float _11, float _12, float _13,
        float _21, float _22, float _23
        //,float _31, float _32, float _33
    ) {
        this->_11 = _11; this->_12 = _12; this->_13 = _13;
        this->_21 = _21; this->_22 = _22; this->_23 = _23;
        //this->_31 = _31; this->_32 = _32; this->_33 = _33;
    }
    MAT33() {
        identity();
    }
    void identity() {
        _11 = 1; _12 = 0; _13 = 0;
        _21 = 0; _22 = 1; _23 = 0;
        //_31 = 0; _32 = 0; _33 = 1;
    }
    void scaling(float sx, float sy) {
        _11 = sx;
        _22 = sy;
    }
    void rotate(float angle) {
        float c = cos(angle);
        float s = sin(angle);
        _11 = c; _12 = -s;
        _21 = s; _22 = c;
    }
    void translate(float x, float y) {
        _13 = x;
        _23 = y;
    }
    VEC operator*(const VEC& v) {
        return VEC(
            _11 * v.x + _12 * v.y + _13 * 1,
            _21 * v.x + _22 * v.y + _23 * 1
        );
    }
    MAT33 operator*(const MAT33& m) {
        return MAT33(
            _11 * m._11 + _12 * m._21,// + _13 * m._31,
            _11 * m._12 + _12 * m._22,// + _13 * m._32,
            _11 * m._13 + _12 * m._23 + _13,// * m._33,

            _21 * m._11 + _22 * m._21,// +_23 * m._31,
            _21 * m._12 + _22 * m._22,// + _23 * m._32,
            _21 * m._13 + _22 * m._23 + _23// * m._33
            //,_31 + m._11 + _32 * m._21 + _33 * m._31,
            //_31 + m._12 + _32 * m._22 + _33 * m._32,
            //_31 + m._13 + _32 * m._23 + _33 * m._33
        );
    }
};

#include<vector>
void background() {
    fill(0, 0, 20); noStroke(); rect(0, 0, width, height);
}
void gmain() {
    window(1080, 1080, full);
    hideCursor();
    angleMode(DEGREES);
    colorMode(HSV);
    float satu = 128;
    float bright = 255;
    std::vector<COLOR> c;
    std::vector<VEC> ops;
    int num = 10;
    float angle = 360.0f / num;
    for (int i = 0; i < num; i++) {
        float r = 0.5f + 0.5f * !(i % 2);
        ops.emplace_back(sin(angle * i) * r, cos(angle * i) * r);
        c.emplace_back(angle * i, satu, bright);
    }
    std::vector<VEC> ps;
    MAT33 tm, rm, sm, rm2;
    angle = 0;
    int sw = 0;
    int numSamples = 8;
    while (notQuit) {
        if (isTrigger(KEY_SPACE)) {
            ++sw %= numSamples;
            angle = 0;
        }

        switch (sw) {
        case 0: {
            background();
            axisMode(DRAW);
            mathAxis(2, 128);

            rm.rotate(angle);
            angle += 2.5f;
            MAT33 m = rm;

            ps = ops;
            for (VEC& pt : ps) {
                pt = m * pt;
            }

            for (int i = 2; i < 3; i++) {

                strokeWeight(20);
                stroke(c[i]);
                mathPoint(ops[i].x, ops[i].y);
                mathPoint(ps[i].x, ps[i].y);
                int j = (i + 1) % ps.size();
                //mathLine(ps[i].x, ps[i].y, ps[j].x, ps[j].y);
            }
            break;
        }
        case 1: {
            background();
            axisMode(DRAW);
            mathAxis(2, 128);

            rm.rotate(angle);
            sm.scaling(0.2f, 0.7f);
            angle += 2.5f;
            MAT33 m = sm * rm;

            ps = ops;
            for (VEC& pt : ps) {
                pt = m * pt;
            }

            for (int i = 2; i < 3; i++) {

                strokeWeight(20);
                stroke(c[i]);
                mathPoint(ops[i].x, ops[i].y);
                mathPoint(ps[i].x, ps[i].y);
                int j = (i + 1) % ps.size();
                //mathLine(ps[i].x, ps[i].y, ps[j].x, ps[j].y);
            }
            break;
        }
        case 2: {
            background();
            //axisMode(NODRAW);
            mathAxis(2, 128);

            //rm2.rotate(angle);
            tm.translate(1, 0);
            rm.rotate(angle * 4);
            sm.scaling(0.5f, 0.5f);
            angle += 2.5f;
            MAT33 m = sm * rm;

            ps = ops;
            for (VEC& pt : ps) {
                pt = m * pt;
            }

            for (int i = 2; i < 3; i++) {
                strokeWeight(20);
                stroke(c[i]);
                mathPoint(ops[i].x, ops[i].y);
                mathPoint(ps[i].x, ps[i].y);
                int j = (i + 1) % ps.size();
                //mathLine(ps[i].x, ps[i].y, ps[j].x, ps[j].y);
            }
            break;
        }
        case 3: {
            background();
            //axisMode(NODRAW);
            mathAxis(2, 128);

            //rm2.rotate(angle);
            tm.translate(1, 0);
            rm.rotate(angle * 4);
            sm.scaling(0.5f, 0.5f);
            angle += 2.5f;
            MAT33 m = tm * sm * rm;

            ps = ops;
            for (VEC& pt : ps) {
                pt = m * pt;
            }

            for (int i = 2; i < 3; i++) {
                strokeWeight(20);
                stroke(c[i]);
                mathPoint(ops[i].x, ops[i].y);
                mathPoint(ps[i].x, ps[i].y);
                int j = (i + 1) % ps.size();
                //mathLine(ps[i].x, ps[i].y, ps[j].x, ps[j].y);
            }
            break;
        }
        case 4: {
            background();
            //axisMode(NODRAW);
            mathAxis(2, 128);

            rm2.rotate(angle);
            tm.translate(1, 0);
            rm.rotate(angle * 4);
            sm.scaling(0.5f, 0.5f);
            angle += 2.5f;
            MAT33 m = rm2 * tm * sm * rm;

            ps = ops;
            for (VEC& pt : ps) {
                pt = m * pt;
            }

            for (int i = 2; i < 3; i++) {
                strokeWeight(20);
                stroke(c[i]);
                mathPoint(ops[i].x, ops[i].y);
                mathPoint(ps[i].x, ps[i].y);
                int j = (i + 1) % ps.size();
                //mathLine(ps[i].x, ps[i].y, ps[j].x, ps[j].y);
            }
            break;
        }
        case 5: {
            background();
            axisMode(DRAW);
            mathAxis(2, 128);

            rm2.rotate(angle);
            tm.translate(1, 0);
            rm.rotate(angle * 4);
            sm.scaling(0.25f, 0.5f);
            angle += 0.5f;
            MAT33 m = rm2 * tm * sm * rm;

            ps = ops;
            for (VEC& pt : ps) {
                pt = m * pt;
            }

            for (int i = 0; i < ps.size(); i++) {
                strokeWeight(10);
                stroke(c[i]);
                mathPoint(ops[i].x, ops[i].y);
                mathPoint(ps[i].x, ps[i].y);
                int j = (i + 1) % ps.size();
                //mathLine(ps[i].x, ps[i].y, ps[j].x, ps[j].y);
            }
            break;
        }
        case 6: {
            background();
            axisMode(DRAW);
            mathAxis(2, 128);

            rm2.rotate(angle);
            tm.translate(1, 0);
            rm.rotate(angle * 4);
            sm.scaling(0.25f, 0.5f);
            angle += 0.5f;
            MAT33 m = rm2 * tm * sm * rm;

            ps = ops;
            for (VEC& pt : ps) {
                pt = m * pt;
            }

            for (int i = 0; i < ps.size(); i++) {
                strokeWeight(10);
                stroke(c[i]);
                //mathPoint(ops[i].x, ops[i].y);
                mathPoint(ps[i].x, ps[i].y);
                int j = (i + 1) % ps.size();
                //mathLine(ps[i].x, ps[i].y, ps[j].x, ps[j].y);
            }
            break;
        }
        case 7: {
            background();
            axisMode(NODRAW);
            mathAxis(2, 128);

            rm2.rotate(angle);
            tm.translate(1, 0);
            rm.rotate(angle * 4);
            sm.scaling(0.25f, 0.5f);
            angle += 0.5f;
            MAT33 m = rm2 * tm * sm * rm;

            ps = ops;
            for (VEC& pt : ps) {
                pt = m * pt;
            }

            for (int i = 0; i < ps.size(); i++) {
                strokeWeight(10);
                stroke(c[i]);
                //mathPoint(ops[i].x, ops[i].y);
                mathPoint(ps[i].x, ps[i].y);
                int j = (i + 1) % ps.size();
                mathLine(ps[i].x, ps[i].y, ps[j].x, ps[j].y);
            }
            break;
        }
        }//end of switch
    }
}
#endif



