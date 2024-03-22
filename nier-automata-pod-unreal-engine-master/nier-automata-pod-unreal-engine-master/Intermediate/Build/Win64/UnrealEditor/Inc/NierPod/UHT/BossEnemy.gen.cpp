// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NierPod/BossEnemy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBossEnemy() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	NIERPOD_API UClass* Z_Construct_UClass_ABossEnemy();
	NIERPOD_API UClass* Z_Construct_UClass_ABossEnemy_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NierPod();
// End Cross Module References
	void ABossEnemy::StaticRegisterNativesABossEnemy()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABossEnemy);
	UClass* Z_Construct_UClass_ABossEnemy_NoRegister()
	{
		return ABossEnemy::StaticClass();
	}
	struct Z_Construct_UClass_ABossEnemy_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABossEnemy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_NierPod,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABossEnemy_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABossEnemy_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "BossEnemy.h" },
		{ "ModuleRelativePath", "BossEnemy.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABossEnemy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABossEnemy>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABossEnemy_Statics::ClassParams = {
		&ABossEnemy::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABossEnemy_Statics::Class_MetaDataParams), Z_Construct_UClass_ABossEnemy_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ABossEnemy()
	{
		if (!Z_Registration_Info_UClass_ABossEnemy.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABossEnemy.OuterSingleton, Z_Construct_UClass_ABossEnemy_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABossEnemy.OuterSingleton;
	}
	template<> NIERPOD_API UClass* StaticClass<ABossEnemy>()
	{
		return ABossEnemy::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABossEnemy);
	ABossEnemy::~ABossEnemy() {}
	struct Z_CompiledInDeferFile_FID_Users_admin_Desktop_PodGit_Pod_nier_automata_pod_unreal_engine_master_nier_automata_pod_unreal_engine_master_Source_NierPod_BossEnemy_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_admin_Desktop_PodGit_Pod_nier_automata_pod_unreal_engine_master_nier_automata_pod_unreal_engine_master_Source_NierPod_BossEnemy_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABossEnemy, ABossEnemy::StaticClass, TEXT("ABossEnemy"), &Z_Registration_Info_UClass_ABossEnemy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABossEnemy), 2992447237U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_admin_Desktop_PodGit_Pod_nier_automata_pod_unreal_engine_master_nier_automata_pod_unreal_engine_master_Source_NierPod_BossEnemy_h_982614117(TEXT("/Script/NierPod"),
		Z_CompiledInDeferFile_FID_Users_admin_Desktop_PodGit_Pod_nier_automata_pod_unreal_engine_master_nier_automata_pod_unreal_engine_master_Source_NierPod_BossEnemy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_admin_Desktop_PodGit_Pod_nier_automata_pod_unreal_engine_master_nier_automata_pod_unreal_engine_master_Source_NierPod_BossEnemy_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
