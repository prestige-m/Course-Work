#pragma once
#ifndef OPEN_BOX_H
#define OPEN_BOX_H
#include "Box.hpp"

#include <SFML\Graphics.hpp>
#include "ResourceManager.hpp"
#include <cmath>
#include <iostream>
#include "Event.hpp"

const sf::Color BOX_COLOR = { 0, 0, 0, 50 };  //���� ����
const sf::Color BOX_BORDER_COLOR = { 0, 0, 0, 130 }; //���� �������
const float BOX_BORDER = 2.f; //������� �������
const float MOVE_SPEED = 140.f;
const int MAX_UINT8 = 255;
const int ALPHA_SHIFT = 100;

enum DIRECTION {
	LEFT = -2,
	UP,
	NONE,
	DOWN,
	RIGHT
};

class OpenBox : public Box {
	unsigned short value; //���� ��������
	sf::Sprite *sprite;

	float offset;
	DIRECTION direction;
	bool swap_state;
	float alpha;
	int alphaShift;

public:
	OpenBox();
	~OpenBox();
	void SetPosition(float x, float y) override;      //�-� ������������� ��������� Box
	void Update(sf::RenderWindow& window, float time) override;   //��������� �������
	void Draw(sf::RenderWindow& window) override;  //��������� �� �����
	bool inMotion() { return offset > 0; }
	bool isFill() { return value != 0; }
	void BackToOrigin();
	
	bool operator==(const OpenBox& other) { return value == other.value; }
	bool operator!=(const OpenBox& other) { return !(*this == other); }

	void Move(float time);
	bool isClicked(sf::RenderWindow& window);
	void SetValue(unsigned short _value);
	void SetTexture(const sf::Texture& _texture);
	void SetTexture(const sf::Texture& _texture, const sf::IntRect& _rect);
	void SetSprite(const sf::Sprite& _sprite) { *sprite = _sprite; }
	void SetDirection(DIRECTION _dir);
	void SetSwapState(bool _swapState) { swap_state = _swapState; }
	void SetAlphaLevel(int alphaShift, float _alpha = MAX_UINT8);
	
	float GetAlphaLevel();
	bool GetSwapState() { return swap_state; }
	DIRECTION GetDirection() { return direction; }
	sf::Sprite& GetSprite() { return *sprite; }
	sf::Vector2f GetOffset(DIRECTION dir, float time);
	sf::Texture GetTexture();
	unsigned short GetValue();
};

#endif //OPEN_BOX_H

