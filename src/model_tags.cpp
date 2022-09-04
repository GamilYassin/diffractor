// This file is part of the Diffractor photo and video organizer
// Copyright(C) 2022  Zac Walker
//
// This program is free software; you can redistribute it and / or modify it
// under the terms of the LGPL License either version 2.1 or later.
// License details are available at https://www.gnu.org/licenses/lgpl-2.1.html
//
// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY

#include "pch.h"
#include "model_tags.h"


void tag_set::make_unique()
{
	std::ranges::sort(_tags, df::iless());
	_tags.erase(std::ranges::unique(_tags).begin(), _tags.end());
}

void tag_set::add(const tag_set& other)
{
	_tags.insert(_tags.cend(), other._tags.cbegin(), other._tags.cend());
	make_unique();
}

void tag_set::remove(const tag_set& other)
{
	const df::hash_set<std::u8string_view, df::ihash, df::ieq> unique(other._tags.cbegin(), other._tags.cend());
	std::erase_if(_tags, [&unique](const std::u8string_view tag) { return unique.contains(tag); });
}
