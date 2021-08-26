#define _MAT

#ifdef _MAT

#include"libOne.h"
void gmain() {
    window(1000, 1000);
    while (notQuit) {
        clear();
        mathAxis(3.1f, 255);
    }
}

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
            //�P�s��
            _11 * m._11 + _12 * m._21,//�P�s�P��̗v�f
            _11 * m._12 + _12 * m._22,//�P�s�Q��̗v�f
            //�Q�s��
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
    MAT22 mat;//���������s��

    while (notQuit) {
        background();
        mathAxis(2.1f,255);
        //�e�s�������
        sm.scaling(0.5f,2.0f);
        angle += 1;
        rm.rotate(angle);
        //�s�����������
        mat = sm * rm;
        //���W�ϊ�����
        p = mat * op;
        //�`��
        strokeWeight(20);
        stroke(c);
        //���̍��W
        mathPoint(op.x, op.y);
        //�ϊ���̍��W
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
    //�P�ʍs�������
    void identity() {
        _11 = 1; _12 = 0; _13 = 0;
        _21 = 0; _22 = 1; _23 = 0;
        _31 = 0; _32 = 0; _33 = 1;
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
    //���s�ړ��s�������
    void translate(float x, float y) {
        _13 = x;
        _23 = y;
    }
    //�u�R�s�R��s��v�Ɓu�Q�s�P��s��i�Q�����x�N�g���j�{�P�s�v�̊|���Z
    VEC operator*(const VEC& v) {
        return VEC(
            _11 * v.x + _12 * v.y + _13 * 1,
            _21 * v.x + _22 * v.y + _23 * 1
        );
    }
    //�R�s�R��s��ǂ����̊|���Z
    MAT33 operator*(const MAT33& m) {
        return MAT33(
            //�P�s��
            _11 * m._11 + _12 * m._21 + _13 * m._31,
            _11 * m._12 + _12 * m._22 + _13 * m._32,
            _11 * m._13 + _12 * m._23 + _13 * m._33,
            //�Q�s��
            _21 * m._11 + _22 * m._21 + _23 * m._31,
            _21 * m._12 + _22 * m._22 + _23 * m._32,
            _21 * m._13 + _22 * m._23 + _23 * m._33,
            //�R�s��
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
        //�e�s�������
        rm2.rotate(angle);
        tm.translate(1, 0);
        rm.rotate(angle*4);
        sm.scaling(0.4f, 0.4f);
        angle += 1;
        //�s�����������
        mat = rm2 * tm * rm * sm;
        //���W�ϊ�
        p = mat * op;
        //�`��
        strokeWeight(20);
        stroke(c);
        mathPoint(op.x, op.y);//���̍��W
        mathPoint(p.x, p.y);//�ϊ���̍��W
    }
}
#endif

#ifdef _MAT33_OPT
//---------------------------------------------------------------------
//�u�s��N���X�̍œK���v�Ɓu���`�A�j���[�V�����v
//---------------------------------------------------------------------

#include"libOne.h"
//VEC�͕ύX�Ȃ�
class VEC {
public:
    float x, y;
    VEC(float x = 0, float y = 0) {
        this->x = x;
        this->y = y;
    }
};

//---------------------------------------------------------------------
//�s��̗v�f_31,_32,_33��0,0,1�̂܂ܕω����Ȃ����ߏȗ����邱�Ƃ��ł���
//---------------------------------------------------------------------
class MAT33 {
public:
    float _11, _12, _13;
    float _21, _22, _23;
    //float _31, _32, _33;
    MAT33(float _11=1, float _12=0, float _13=0,
          float _21=0, float _22=1, float _23=0//,
          //float _31=0, float _32=0, float _33=1
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
            _11 * v.x + _12 * v.y + _13,// * 1,��1�͊|����K�v���Ȃ�
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
            _21 * m._13 + _22 * m._23 + _23// * m._33,
            //_31 + m._11 + _32 * m._21 + _33 * m._31,
            //_31 + m._12 + _32 * m._22 + _33 * m._32,
            //_31 + m._13 + _32 * m._23 + _33 * m._33
        );
    }
};

//------------------------------------------------------------------------
//���`�ɗp�ӂ������W���s��œ�����
//------------------------------------------------------------------------
void background() {
    fill(0, 0, 20); noStroke(); rect(0, 0, width, height);
}
void gmain() {
    window(1080, 1080, full);
    hideCursor();
    angleMode(DEGREES);
    colorMode(HSV);
    //���W��z��ŕ����p�ӂ���
    const int num = 10;
    VEC op[num];
    VEC p[num];
    COLOR c[num];
    //���`�ɂȂ���W��ݒ�
    float theta = 360.0f / num;
    for (int i = 0; i < num; i++) {
        float r = 1.0f - 0.5f * (i % 2);//radius
        op[i] = VEC(sin(theta * i) * r, cos(theta * i) * r);
        c[i] = COLOR(theta * i, 128, 255);
    }
    //�S�s��
    MAT33 mat, tm, rm, sm, rm2;
    float angle = 0;
    while (notQuit) {
        background();
        axisMode(NODRAW);
        mathAxis(2, 128);
        //�s�������
        rm2.rotate(angle);
        tm.translate(1, 0);
        sm.scaling(0.25f, 0.5f);
        rm.rotate(angle * 4);
        angle += 0.5f;
        //�s�����������
        mat = rm2 * tm * sm * rm;
        //���W�ϊ�����
        for (int i = 0; i < num; i++) {
            p[i] = mat * op[i];
        }
        //�`�悷��
        for (int i = 0; i < num; i++) {
            strokeWeight(10);
            stroke(c[i]);
            mathPoint(op[i].x, op[i].y);
            mathPoint(p[i].x, p[i].y);
            int j = (i + 1) % num;//i���Ō�̍��W���w���Ƃ��A����0�Ƃ���
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
        float r = 1.0f - 0.5f * (i % 2);
        op.emplace_back(sin(angle * i) * r, cos(angle * i) * r);
        c.emplace_back(angle * i, 128, 255);
    }
    std::vector<VEC> p = op;
    
    MAT33 mat, tm, rm, sm, rm2;
    angle = 0;

    int numSamples = 8;
    int no = 0;
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

/*
//--------------------------------------------------------
//�œK�����ꂽMAT33���m�̊|���Z
//--------------------------------------------------------
void mulTranslate(float x, float y) {
    // |_11 _12 _13|    |1  0  x| �@ |_11  _12  _11x+_12y+_13| 
    // |_21 _22 _23| �~ |0  1  y| �� |_21  _22  _21x+_22y+_23|
    // |  0   0   1|    |0  0  1|    |  0    0              1|
    _13 += _11 * x + _12 * y;
    _23 += _21 * x + _22 * y;
}
void mulScaling(float x, float y) {
    // |_11 _12 _13|    |x  0  0| �@ |_11x _12y _13|
    // |_21 _22 _23| �~ |0  y  0| �� |_21x _22y _23|
    // |  0   0   1|    |0  0  1|    |  0    0    1|
    _11 *= x;    _12 *= y;
    _21 *= x;    _22 *= y;
}
void mulRotate(float angle) {
    // |_11 _12 _13|    |c -s  0| �@ |_11c+_12s   _11(-s)+_12c   _13|
    // |_21 _22 _23| �~ |s  c  0| �� |_21c+_22s   _21(-s)+_22c   _23|
    // |  0   0   1|    |0  0  1|    |        0             0      1|
    float c = cos(angle);
    float s = sin(angle);
    float tmp;
    //1�s��
    tmp = _11 * c + _12 * s;
    _12 = _11 * -s + _12 * c;
    _11 = tmp;
    //2�s��
    tmp = _21 * c + _22 * s;
    _22 = _21 * -s + _22 * c;
    _21 = tmp;
}
*/
