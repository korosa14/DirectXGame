﻿#include "Enemy.h"
#include "MathUtilityForText.h"

void Enemy::Initialize(const std::vector<Model*>& models) {
	//基底クラスの初期化
	BaseCharacter::Initialize(models);

	//ワールド変換の初期化
	worldTransformBody_.Initialize();
	worldTransformBody_.parent_ = &worldTransform_;

	worldTransformL_arm_.Initialize();
	worldTransformL_arm_.parent_ = &worldTransformBody_;
	worldTransformL_arm_.translation_.x = -0.87337f;
	worldTransformL_arm_.translation_.y = 1.01077f;

	worldTransformR_arm_.Initialize();
	worldTransformR_arm_.parent_ = &worldTransformBody_;
	worldTransformR_arm_.translation_.x = +0.87337f;
	worldTransformR_arm_.translation_.y = 1.01077f;
}

void Enemy::Update() {
	//ギミックの更新
	UpdateGimmick();

	//移動速さ
	const float speed = 0.1f;

	worldTransform_.rotation_.y += 0.01f;

	//移動量
	Vector3 move = { 0.0f,0.0f,speed };
	//回転行列
	Matrix4x4 matRotY = MakeRotateXMatrix(worldTransform_.rotation_.y);
	//移動量を回転に合わせて回転させる
	move = TransformNormal(move, matRotY);
	//移動
	worldTransform_.translation_ += move;

	//行列を更新
	worldTransform_.UpdateMatrix();
	worldTransformBody_.UpdateMatrix();
	worldTransformL_arm_.UpdateMatrix();
	worldTransformR_arm_.UpdateMatrix();
}

void Enemy::Draw(const ViewProjection& viewProjection) {
	//3Dモデルを描画
	models_[kModelIndexBody]->Draw(worldTransformBody_, viewProjection);
}
