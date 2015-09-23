#pragma once

/**
* @file PlaybackManager.h
* @ingroup fx
* The PlaybackManager class.
*/

#include "PlaybackCategory.h"
#include "devices/IDevice.h"
#include "ISound.h"

#include <unordered_map>
#include <memory>

AUD_NAMESPACE_BEGIN

/**
* This class allows to control groups of playing sounds easily.
* The sounds are part of categories.
*/
class AUD_API PlaybackManager
{
private:
	/**
	* Unordered map of categories, each category has different name.
	*/
	std::unordered_map<unsigned int, std::shared_ptr<PlaybackCategory>> m_categories;

	/**
	* Device used for playback.
	*/
	std::shared_ptr<IDevice> m_device;

	/**
	* The current key used for new categories.
	*/
	unsigned int m_currentKey;

	// delete copy constructor and operator=
	PlaybackManager(const PlaybackManager&) = delete;
	PlaybackManager& operator=(const PlaybackManager&) = delete;

public:
	/**
	* Creates a new PlaybackManager.
	* \param A shared pointer to the device which will be used for playback.
	*/
	PlaybackManager(std::shared_ptr<IDevice> device);

	/**
	* Adds an existent category to the manager and returns a key to access it.
	* \param category The category to be added.
	* \return The category key.
	*/
	unsigned int addCategory(std::shared_ptr<PlaybackCategory> category);

	/**
	* Plays a sound and adds it to a new or existent category.
	* \param sound The sound to be played and added to a category.
	* \param catKey Key of the category.
	* \return The handle of the playback.
	*/
	std::shared_ptr<IHandle> play(std::shared_ptr<ISound> sound, unsigned int catKey);

	/**
	* Resumes all the paused sounds of a category.
	* \param catKey Key of the category.
	* \return
	*        - true if succesful.
	*        - false if the category doesn't exist.
	*/
	bool resume(unsigned int catKey);

	/**
	* Pauses all current playing sounds of a category.
	* \param catKey Key of the category.
	* \return
	*        - true if succesful.
	*        - false if the category doesn't exist.
	*/
	bool pause(unsigned int catKey);

	/**
	* Retrieves the volume of a category.
	* \param catKey Key of the category.
	* \return The volume value of the category. If the category doesn't exist it returns a negative number.
	*/
	float getVolume(unsigned int catKey);

	/**
	* Sets the volume for a category.
	* \param volume The volume.
	* \param catKey Key of the category.
	* \return
	*        - true if succesful.
	*        - false if the category doesn't exist.
	*/
	bool setVolume(float volume, unsigned int catKey);

	/**
	* Stops and erases a category of sounds.
	* \param catKey Key of the category.
	* \return
	*        - true if succesful.
	*        - false if the category doesn't exist.
	*/
	bool stop(unsigned int catKey);

	/**
	* Removes all the invalid handles of all the categories.
	*/
	void clean();

	/**
	* Removes all the invalid handles of a category.
	* \param catKey Key of the category.
	* \return
	*        - true if succesful.
	*        - false if the category doesn't exist.
	*/
	bool clean(unsigned int catKey);
};

AUD_NAMESPACE_END
