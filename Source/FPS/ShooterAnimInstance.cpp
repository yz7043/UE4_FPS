// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAnimInstance.h"
#include "ShooterCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
void UShooterAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	if (ShooterCharacter == nullptr)
	{
		ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
	}
	if (ShooterCharacter)
	{
		// Get the speed of the character
		FVector Velocity{ ShooterCharacter->GetVelocity() };
		Velocity.Z = 0;
		speed = Velocity.Size(); // Speed does not take Z direction value into account

		// Is the character in the air
		bIsInAir = ShooterCharacter->GetCharacterMovement()->IsFalling();
		
		// Is the character accelerating
		if (ShooterCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f)
			bIsAccelerating = true;
		else
			bIsAccelerating = false;
	}
}

void UShooterAnimInstance::NativeInitializeAnimation()
{
	ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
}
