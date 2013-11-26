#include <SDL.h>


#define _(_) strcpy((char*)s, f[1]); strcat((char*)s, "/" #_ ".bmp"); \
	SDL_Surface* _ = SDL_LoadBMP((char*)s); _ || fprintf(stderr, "Load err\n"); \
	SDL_SetColorKey(_, SDL_SRCCOLORKEY, SDL_MapRGB(_->format, 255, 0, 255)); _ = SDL_DisplayFormat(_);


#define   D        ( SDL_BlitSurface)
#define   E        (e.key.keysym.sym)
#define   A(a,b)   (a  <  b ?  a : b)
#define   T        0,c,&r);
#define   H        800
#define   S        600


void X(SDL_Surface* s, Uint32 c, int x, int w, int y, int d)
{
	Uint32 *p = s->pixels + y * s->pitch + x * s->format->BytesPerPixel;
	while (p += d, w-- > 0) *p = c;
}

int Y(SDL_Surface* s, Uint32 t, int y, int x)
{
	Uint8 *p;
	
	do {
		p = (Uint8 *)s->pixels + y++ * s->pitch + x * s->format->BytesPerPixel;
	} while ((*p != t) && (y < S));
	
	return --y;
}


int main(int b, char* f[])
{
	int j;
	SDL_Rect r;
	SDL_Event e;
	struct { int p,l,a,y,e,r,s; } s[4], *q, *p;

	SDL_Init(SDL_INIT_VIDEO);

	b == 2 || fprintf(stderr, "No arg\n") && *(int*)0;
	
	SDL_Surface* c = SDL_SetVideoMode(H, S, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	c || fprintf(stderr, "Video err\n");


	_(L)_(o)_(a)_(d)_(i)_(n)_(g)  _(I)_(M)_(G)


	while (H) {
		/* new game */
		n: memset(&s, 0, sizeof(s));
		for (j = 0; j < 4; j++) {
			s[j].p = j * 395 + 150;
			s[j].l = 32;
		}

		while (q = &s[0], p = &s[1]) {
			D(L, 0, c, 0);

			while (SDL_PollEvent(&e)) {
				switch (e.type) {
					case SDL_QUIT: return 0;
						#define K(k) E == SDLK_##k)
					case SDL_KEYDOWN:
						if (K(ESCAPE) return 0;
						if (K(a) q->e = -3;
						if (K(d) q->e = 3;
						if ((K(w) && q->r < 5) q->r = 5;
						if (K(LSHIFT) q->s = q->y + 18;
						if (K(LEFT) p->e = -3;
						if (K(RIGHT) p->e = 3;
						if ((K(UP) && p->r < 5) p->r = 5;
						if (K(RCTRL) p->s = p->y + 18;
						E=0;
					case SDL_KEYUP:
						if ((K(a) || K(d) q->e = 0;
						if ((K(LEFT) || K(RIGHT) p->e = 0;
				}
			}

			do {
				r.x = q->p; r.y = q->y;
				X(c, 0xFD02FF, q->p + q->l, 32 - q->l, q->y - 6, 1);
				
				if (p->l <= 0) {
					r.x = 358; r.y = 150;
					D(L, 0, c, 0); D(G, T
					r.x += 26; r.y += 75;
					D(&s[0] == p ? M : I, T
					p->l--;
					if (p->l <= -100) goto n; else goto X;
				}
				
				/* move */
				q->e && (q->a = q->e/3);
				q->p + q->e + 32 < H && q->e + q->p > 0 && (q->p += q->e);
				X(c, 0xFE01, q->p, q->l, q->y - 6, 1);
				if (q->r > 0) {
					q->y -= q->r-- * 5;
				} else {
					j = A(Y(o, 0, q->y + 48, q->p), Y(o, 0, q->y + 48, q->p+32)) - 48 - q->y;
					if (j > 0) q->y += A(j, 10);
				}
				D(q->l == 0 ? d : q->a < 0 ? d : a, T
				(q->y < 0 || q->y > S) && (q->y = 0);

				/* grav */
				if (q->s > 0) {
					!q->a && (q->a = 1);
					for (j = q->p; j >= 0 && j <= H; j += q->a) {
						if (p->l && (p->p == j || p->p + 32 == j) && p->y < q->s && p->y + 48 > q->s) goto O;
					}
					goto U;
					O: p->l -= 4;
					U: q->l == 0 && D(q->l == 0 ? d : q->a == 1 ? a : d, T
					C: q->a == 1 ? X(c, 0x314159, q -> p + 32 + 3, (j - q -> p - 32 + 3) / 3, q->s, 3) : X(c, 0x271828 * E / S, ++j, (q -> p - j - 3) / 3, q->s, 3),
					q->s = -15;
				} else if (q->s < 0) {
					q->s++;
					r.x += q->a == 1 ? 32 : -12;
					r.y += 12;
					D(q->a == 1 ? n : g, T
				}
			} while (p=&s[0],q++,q!=&s[2]);

			/* 30fps */
			X: SDL_Flip(c);
			j = SDL_GetTicks();
			SDL_Delay(10);
			while (SDL_GetTicks() - j < 16);
		}
	}

	SDL_Quit();
	return 0;
}

