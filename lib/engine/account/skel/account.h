
/*
 * Ekiga -- A VoIP and Video-Conferencing application
 * Copyright (C) 2000-2007 Damien Sandras

 * This program is free software; you can  redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version. This program is distributed in the hope
 * that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * Ekiga is licensed under the GPL license and as a special exception, you
 * have permission to link or otherwise combine this program with the
 * programs OPAL, OpenH323 and PWLIB, and distribute the combination, without
 * applying the requirements of the GNU GPL to the OPAL, OpenH323 and PWLIB
 * programs, as long as you do follow the requirements of the GNU GPL for all
 * the rest of the software thus combined.
 */


/*
 *                         account.h  -  description
 *                         ------------------------------------------
 *   begin                : written in 2008 by Damien Sandras
 *   copyright            : (c) 2008 by Damien Sandras
 *   description          : declaration of the interface of an AccountManager 
 *                          Account
 *
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <set>
#include <map>
#include <string>

#include "chain-of-responsibility.h"
#include "form-request.h"
#include "menu-builder.h"

namespace Ekiga
{

/**
 * @addtogroup accounts 
 * @{
 */

  class Account
  {
  public:

    /** The destructor.
     */
    virtual ~Account () { }


    /** Returns the name of the Ekiga::Account.
     * This function is purely virtual and should be implemented by the
     * Ekiga::Account descendant.
     * @return The name of the Ekiga::Contact.
     */
    virtual const std::string get_name () const = 0;


    /** Returns the protocol name of the Ekiga::Account.
     * This function is purely virtual and should be implemented by the
     * Ekiga::Account descendant.
     * @return The protocol name of the Ekiga::Contact.
     */
    virtual const std::string get_protocol_name () const = 0;


    /** Returns the address of record for that Ekiga::Account.
     * @return The address of record.
     */
    virtual const std::string get_aor () const = 0;


    /** Returns the hostname for the Ekiga::Account.
     * This function is purely virtual and should be implemented by the
     * Ekiga::Account descendant.
     * @return The host name of the Ekiga::Account.
     */
    virtual const std::string get_host () const = 0;


    /** Returns the user name for the Ekiga::Account.
     * This function is purely virtual and should be implemented by the
     * Ekiga::Account descendant.
     * @return The user name of the Ekiga::Account.
     */
    virtual const std::string get_username () const = 0;


    /** Returns the authentication user name for the Ekiga::Account.
     * This function is purely virtual and should be implemented by the
     * Ekiga::Account descendant.
     * @return The authentication user name of the Ekiga::Account.
     */
    virtual const std::string get_authentication_username () const = 0;


    /** Returns the password for the Ekiga::Account.
     * This function is purely virtual and should be implemented by the
     * Ekiga::Account descendant.
     * @return The password of the Ekiga::Account.
     */
    virtual const std::string get_password () const = 0;


    /** Returns the registration timeout for the Ekiga::Account.
     * This function is purely virtual and should be implemented by the
     * Ekiga::Account descendant.
     * @return The timeout of the Ekiga::Account.
     */
    virtual unsigned get_timeout () const = 0;


    /** Subscribe the given account.
     * This function is purely virtual and should be implemented by the
     * Ekiga::Account descendant.
     */
    virtual void enable () = 0;


    /** Unsubscribe the given account.
     * This function is purely virtual and should be implemented by the
     * Ekiga::Account descendant.
     */
    virtual void disable () = 0;


    /** Return true if the account is active.
     * It does not mean that the account is successfully registered, it
     * just means it is active.
     * This function is purely virtual and should be implemented by the
     * Ekiga::Account descendant.
     */
    virtual bool is_enabled () const = 0;
    
    
    /** Create the menu for that account and its actions.
     * This function is purely virtual and should be implemented by
     * the descendant of the Ekiga::Contact.
     * @param A MenuBuilder object to populate.
     */
    virtual bool populate_menu (MenuBuilder &) = 0;


    /**
     * Signals on that object
     */

    /** This signal is emitted when the Account has been updated.
     */
    sigc::signal<void> updated;


    /** This signal is emitted when the Account has been removed.
     */
    sigc::signal<void> removed;


    /** This chain allows the Account to present forms to the user
     */
    ChainOfResponsibility<FormRequest*> questions;
  };

/**
 * @}
 */

};
#endif