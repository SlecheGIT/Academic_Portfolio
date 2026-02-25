class pontos
{
public:
    float x, y;

public:
    pontos(float x0 = 0, float y0 = 0){ x=x0, y=y0; }

    float getx(){ return x; }
    void setx(float x0){ x = x0; }

    float gety(){ return y; }
    void sety(float y0){ y = y0; }

    bool operator== (pontos cord) {
        return ((x == cord.x) && (y == cord.y));
    }
    bool operator!= (pontos cord) {
        return ((x != cord.x) && (y != cord.y));
    }

    pontos operator+ (pontos cord) {
        pontos soma;
        soma.x = x + cord.x;
        soma.y = y + cord.y;
        return soma;
    }
    pontos operator- (pontos cord) {
        pontos subtracao;
        subtracao.x = x - cord.x;
        subtracao.y = y - cord.y;
        return subtracao;
    }

    pontos &operator++ () {
        ++x, ++y;
        return *this;
    }
    pontos operator++ (int) {
        pontos aux = *this;
        x++, y++;
        return aux;
    }
    
    pontos &operator-- () {
        --x, --y;
        return *this;
    }
    pontos operator-- (int) {
        pontos aux = *this;
        x--, y--;
        return aux;
    }
    
};