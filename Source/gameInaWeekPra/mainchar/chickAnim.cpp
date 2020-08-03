// Fill out your copyright notice in the Description page of Project Settings.


#include "chickAnim.h"
#include "chick.h"


void UchickAnim :: update() {

	player = Cast<Achick>(TryGetPawnOwner());

	if (player) {
		player->animState = animState;
	}
}