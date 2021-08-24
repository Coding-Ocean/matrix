#define _MAT
#ifdef _MAT

#endif

#ifdef _MAT22
#include"libOne.h"

//�Q�����x�N�g���i�Q�s�P��̍s��Ƃ��čl���邱�Ƃ��ł���j
class VEC {
public:
    //�s��̗v�f
    float x;
    float y;
    //�R���X�g���N�^
    VEC(float x=0, float y=0) {
        this->x = x;
        this->y = y;
    }
};

//�Q�s�Q��̍s��
class MAT22 {
public:
    //�s��̗v�f
    float _11, _12;
    float _21, _22;
    //�R���X�g���N�^
    MAT22(float _11=1, float _12=0,
          float _21=0, float _22=1 ) {
        this->_11 = _11; this->_12 = _12;
        this->_21 = _21; this->_22 = _22;
    }
    //�P�ʍs�������
    void identity() {
        _11 = 1; _12 = 0;
        _21 = 0; _22 = 1;
    }
    //�g��k���s�������
    void scaling(float sx, float sy) {
        _11 = sx;
        _22 = sy;
    }
    //��]�s�������
    void rotate(float angle) {
        float c = cos(angle);
        float s = sin(angle);
        _11 = c; _12 = -s;
        _21 = s; _22 = c;
    }
    //�u�Q�s�Q��s��v�Ɓu�Q�s�P��s��i�Q�����x�N�g���j�v�̊|���Z
    VEC operator*(const VEC& v) {
        return VEC(
            _11 * v.x + _12 * v.y,
            _21 * v.x + _22 * v.y
        );
    }
    //�Q�s�Q��s��ǂ����̊|���Z
    MAT22 operator*(const MAT22& m) {
        return MAT22(
            _11 * m._11 + _12 * m._21,//�P�s�P��̗v�f
            _11 * m._12 + _12 * m._22,//�P�s�Q��̗v�f
            _21 * m._11 + _22 * m._21,//�Q�s�P��̗v�f
            _21 * m._12 + _22 * m._22 //�Q�s�Q��̗v�f
        );
    }
};

//�w�i�N���A�֐�
void background() {
    fill(0, 0, 60); noStroke(); rect(0, 0, width, height);
}

//�u�P�̍��W�v���u�Q�s�Q��̍s��ŉ�]�A�g��k������v
void gmain() {
    window(1080, 1080, full);
    hideCursor();

    //�_�̐F
    angleMode(DEGREES);
    colorMode(HSV);
    COLOR c(60, 128, 255);
    //���̍��W original position
    VEC op(1, 0.5f);
    //�s��v�Z��̍��W position
    VEC p;
    //�s��
    MAT22 sm;//scaling matrix
    MAT22 rm;//rotate matrix
    float angle = 0;

    while (notQuit) {
        background();
        mathAxis(2.1f,255);
        //�s�������
        sm.scaling(0.5f,2.0f);
        angle += 1;
        rm.rotate(angle);
        MAT22 mat = sm * rm;
        //���W�ϊ�����
        p = mat * op;
        //�`��
        strokeWeight(20);
        stroke(c);
        //���̍��W
        mathPoint(op.x, op.y);
        //�ԊҌ�̍��W
        mathPoint(p.x, p.y);
    }
}
#endif

#ifdef _MAT33
#include"libOne.h"
//�Q�����x�N�g���i�Q�s�P��̍s��Ƃ��čl���邱�Ƃ��ł���j
class VEC {
public:
    float x, y;
    VEC(float x = 0, float y = 0) {
        this->x = x;
        this->y = y;
    }
};
//�R�s�R��̍s��
class MAT33 {
public:
    float _11, _12, _13;
    float _21, _22, _23;
    float _31, _32, _33;
    MAT33(float _11=1, float _12=0, float _13=0,
          float _21=0, float _22=1, float _23=0,
          float _31=0, float _32=0, float _33=1) {
        this->_11 = _11; this->_12 = _12; this->_13 = _13;
        this->_21 = _21; this->_22 = _22; this->_23 = _23;
        this->_31 = _31; this->_32 = _32; this->_33 = _33;
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
    COLOR c(60,128,255);
    VEC op(1, 0.5f);
    VEC p;
    MAT33 mat,sm,rm,tm,rm2;
    float angle = 0;
    while (notQuit) {
        background();
        mathAxis(3, 128);

        sm.scaling(0.4f, 0.4f);
        rm.rotate(angle*4);
        tm.translate(1, 0);
        rm2.rotate(angle);
        mat = rm2 * tm * rm * sm;
        angle += 1;

        p = mat * op;

        strokeWeight(20);
        stroke(c);
        mathPoint(op.x, op.y);
        mathPoint(p.x, p.y);
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
    MAT33(float _11=1, float _12=0, float _13=0,
          float _21=0, float _22=1, float _23=0
        //,float _31, float _32, float _33
    ) {
        this->_11 = _11; this->_12 = _12; this->_13 = _13;
        this->_21 = _21; this->_22 = _22; this->_23 = _23;
        //this->_31 = _31; this->_32 = _32; this->_33 = _33;
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
            _11 * v.x + _12 * v.y + _13,// * 1,
            _21 * v.x + _22 * v.y + _23// * 1
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

void background() {
    fill(0, 0, 20); noStroke(); rect(0, 0, width, height);
}

void gmain() {
    window(1080, 1080, full);
    hideCursor();
    angleMode(DEGREES);
    colorMode(HSV);
    const int num = 10;
    COLOR c[num];
    VEC op[num];
    VEC p[num];
    float angle = 360.0f / num;
    for (int i = 0; i < num; i++) {
        float r = 0.5f + 0.5f * !(i % 2);
        op[i] = VEC(sin(angle * i) * r, cos(angle * i) * r);
        c[i] = COLOR(angle * i, 128, 255);
    }
    MAT33 mat, tm, rm, sm, rm2;
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

        for (int i = 0; i < num; i++) {
            p[i] = m * op[i];
        }

        for (int i = 0; i < num; i++) {
            strokeWeight(10);
            stroke(c[i]);
            mathPoint(op[i].x, op[i].y);
            mathPoint(p[i].x, p[i].y);
            int j = (i + 1) % num;
            mathLine(p[i].x, p[i].y, p[j].x, p[j].y);
        }
    }
}
#endif

#ifdef _MAT33_SAMPLES
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
    MAT33(float _11=1, float _12=0, float _13=0,
          float _21=0, float _22=1, float _23=0
          //,float _31=0, float _32=0, float _33=1
    ) {
        this->_11 = _11; this->_12 = _12; this->_13 = _13;
        this->_21 = _21; this->_22 = _22; this->_23 = _23;
        //this->_31 = _31; this->_32 = _32; this->_33 = _33;
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
    std::vector<COLOR> c;
    std::vector<VEC> op;
    int num = 10;
    float angle = 360.0f / num;
    for (int i = 0; i < num; i++) {
        float r = 0.5f + 0.5f * !(i % 2);
        op.emplace_back(sin(angle * i) * r, cos(angle * i) * r);
        c.emplace_back(angle * i, 128, 255);
    }
    std::vector<VEC> p = op;
    MAT33 mat, tm, rm, sm, rm2;
    angle = 0;
    int no = 0;
    int numSamples = 8;
    while (notQuit) {
        background();
        mathAxis(2, 128);
        
        //print�\���ݒ�
        fill(0, 0, 255);
        printSize(30);

        //�T���v���i���o�[�؂�ւ�
        if (isTrigger(KEY_SPACE)) {
            ++no %= numSamples;
            angle = 0;
        }

        switch (no) {
        case 0:
            print("op[2]����]");
            rm.rotate(angle);
            angle += 2.5f;
            mat = rm;

            p[2] = mat * op[2];

            strokeWeight(20);
            stroke(c[2]);
            mathPoint(op[2].x, op[2].y);
            mathPoint(p[2].x, p[2].y);
        
            break;
        case 1:
            print("op[2]����]���āA�c���ɃX�P�[�����O");
            rm.rotate(angle);
            sm.scaling(0.2f, 0.7f);
            angle += 2.5f;
            mat = sm * rm;

            p[2] = mat * op[2];

            strokeWeight(20);
            stroke(c[2]);
            mathPoint(op[2].x, op[2].y);
            mathPoint(p[2].x, p[2].y);
            break;
        case 2:
            print("op[2]����]���āA0.5�ɃX�P�[�����O");
            rm.rotate(angle);
            sm.scaling(0.5f, 0.5f);
            angle += 10;
            mat = sm * rm;

            p[2] = mat * op[2];

            strokeWeight(20);
            stroke(c[2]);
            mathPoint(op[2].x, op[2].y);
            mathPoint(p[2].x, p[2].y);
            break;
        case 3:
            print("op[2]����]���āA0.5�ɃX�P�[�����O�A�E�ɂP���s�ړ�");
            tm.translate(1, 0);
            rm.rotate(angle);
            sm.scaling(0.5f, 0.5f);
            angle += 10;
            mat = tm * sm * rm;

            p[2] = mat * op[2];

            strokeWeight(20);
            stroke(c[2]);
            mathPoint(op[2].x, op[2].y);
            mathPoint(p[2].x, p[2].y);
            break;
        case 4:
            print("op[2]����]���āA0.5�ɃX�P�[�����O�A�E�ɂP���s�ړ��A����ɉ�]");
            rm2.rotate(angle/4);
            tm.translate(1, 0);
            rm.rotate(angle);
            sm.scaling(0.5f, 0.5f);
            angle += 10;
            mat = rm2 * tm * sm * rm;

            p[2] = mat * op[2];

            strokeWeight(20);
            stroke(c[2]);
            mathPoint(op[2].x, op[2].y);
            mathPoint(p[2].x, p[2].y);
            break;
        case 5:
            print("���ׂĂ� op ����]���āA0.5�ɃX�P�[�����O�A�E�ɂP���s�ړ��A����ɉ�]");
            rm2.rotate(angle/2);
            tm.translate(1, 0);
            rm.rotate(angle);
            sm.scaling(0.25f, 0.5f);
            angle += 2;
            mat = rm2 * tm * sm * rm;

            for (int i = 0; i < p.size(); i++) {
                p[i] = mat * op[i];
            }

            for (int i = 0; i < p.size(); i++) {
                strokeWeight(10);
                stroke(c[i]);
                mathPoint(op[i].x, op[i].y);
                mathPoint(p[i].x, p[i].y);
            }
            break;
        case 6:
            print("op ��\��");
            rm2.rotate(angle / 2);
            tm.translate(1, 0);
            rm.rotate(angle);
            sm.scaling(0.25f, 0.5f);
            angle += 2;
            mat = rm2 * tm * sm * rm;

            for (int i = 0; i < p.size(); i++) {
                p[i] = mat * op[i];
            }

            for (int i = 0; i < p.size(); i++) {
                strokeWeight(10);
                stroke(c[i]);
                mathPoint(p[i].x, p[i].y);
            }
            break;
        case 7:
            print("�_�Ɠ_����Ō���");
            rm2.rotate(angle/2);
            tm.translate(1, 0);
            rm.rotate(angle);
            sm.scaling(0.25f, 0.5f);
            angle += 2;
            mat = rm2 * tm * sm * rm;

            for (int i = 0; i < p.size(); i++) {
                p[i] = mat * op[i];
            }

            for (int i = 0; i < p.size(); i++) {
                strokeWeight(10);
                stroke(c[i]);
                int j = (i + 1) % p.size();
                mathLine(p[i].x, p[i].y, p[j].x, p[j].y);
            }
            break;
        }//end of switch
    }
}
#endif
