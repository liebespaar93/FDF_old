#include <ft_mac_keyboard.h>

int key_press(int keycode, t_param *param) // 어떤 키가 눌렸는지 판단하고,
{                                 // 정의된 행동을 수행하는 함수
	if (keycode == KEY_W)        // W 키를 누르면 param.x값이 1 증가한다.
		param->x++;
	else if (keycode == KEY_S)   // S 키를 누르면 param.x값이 1 감소한다.
		param->x--;
	else if (keycode == KEY_A)   // A 키를 누르면 param.y값이 1 증가한다.
		param->y++;
	else if (keycode == KEY_D)   // D 키를 누르면 param.y값이 1 감소한다.
		param->y--;
	else if (keycode == KEY_ESC) // ESC 키를 누르면 프로그램 종료
		exit(0);
	printf("key : %d  (x, y): (%d, %d)\n",keycode, param->x, param->y); // param의 값 확인
	return (0);
}
