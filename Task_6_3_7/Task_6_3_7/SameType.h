#pragma once
template<typename A, typename B>
struct SameType
{
	static const bool value = false;
};

template <typename A>
struct SameType <A, A> {
	static const bool value = true;
};