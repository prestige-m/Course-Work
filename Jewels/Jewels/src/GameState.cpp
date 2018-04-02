#include "..\inc\GameState.hpp"

GameState::GameState(sf::RenderWindow& _window) {
	game_bg.SetImage("game_bg2");

	grid = new Grid(_window);
	grid->Generate();
	grid->DeleteCopies();
}

void GameState::Update(sf::RenderWindow& window, float _time) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
		grid->Generate();
		grid->DeleteCopies();
	}
	grid->Update(window, _time);
}

void GameState::Draw(sf::RenderWindow &window) {
	grid->Draw(window);
}

void GameState::Destroy() {
	delete grid;
}
